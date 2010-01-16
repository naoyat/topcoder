import java.security.*;
import java.util.*;
public class LaggedGenerator {
    Random r;
    int prime(){
        boolean[] sieve = new boolean[40001];
        int[] primes = new int[4203];
        int p = 0;
        for (int i=2; i<sieve.length; i++) {
            if (!sieve[i]) {
                if (i > 100 && i < 40000) primes[p++] = i;
                for (int j=i*2; j<sieve.length; j+=i) sieve[j] = true;
            }
        }
        int ret = primes[r.nextInt(primes.length)];
        if (ret == 0) return prime();
        else return ret;
    }
    public void generate(int seed) {
        try {
            r = SecureRandom.getInstance("SHA1PRNG");
            r.setSeed(seed);
            int M = (int)(r.nextDouble() * r.nextDouble() * 996) + 5;
            //M = 3;
            int D = r.nextInt(3)+1;
            //D = 1;
            int max = 1+M;
            if (D > 1) max += M * (M+1) / 2;
            if (D > 2) max += M * (M+1) * (M+2) / 6;
            int N = r.nextInt(Math.min(200,max)-1) + 2;
            
            int P = prime();
            int K = r.nextInt((int)Math.min(1000000,3*(long)Math.pow(M,D)) - M+1) + M;
            if (seed == 1) {
                M = 5;
                D = 2;
                N = 4;
                K = 50;
                P = 101;
            }
            int[][] terms = new int[N][D];
            int[] co = new int[N];
            int[] S = new int[K+102*M];
			loop:
            for (int i=0; i<N; i++) {
                int d = r.nextInt(D+1);
                for (int j=0; j<d; j++) terms[i][j] = r.nextInt(M)+1;
                for (int j=d; j<D; j++) terms[i][j] = 0;
                Arrays.sort(terms[i],0,d);
                for(int j = 0; j<i; j++){
                    if (Arrays.equals(terms[i],terms[j])) {
                        i--;
                        continue loop;
                    }
                }
                co[i] = r.nextInt(P);
                //lt.addFatalError(co[i]+" "+terms[i][0]+"\n");
            }

            for (int i=0; i< M; i++) S[i] = r.nextInt(P);
            if (seed == 1) {
                terms = new int[][]{ {0,0}, {1,0}, {5,0}, {2,4} };
                co = new int[]{1,1,1,1};
                for (int i=0; i<5; i++) S[i] = i;
            }

            for (int i=M; i<S.length; i++) {
                for (int j=0; j<N; j++) {
                    int v = co[j];
                    for (int k=0; k<D; k++)
                        if (terms[j][k] > 0) v = v * S[i-terms[j][k]] % P;
                    S[i] = (S[i] + v) % P;
                }
            }
            System.out.println(P);
            System.out.println("*");
            for (int i=0; i<S.length; i++){
                if(i == M || i == 101 * M || i == 101 * M + K)
                    System.out.println("*");
                System.out.println(S[i]);
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        int seed = 1;
        try {
            seed = Integer.parseInt(args[0]);
        } catch(Exception e) {
            System.err.println("Usage: java LaggedGenerator <seed>");
            return;
        }
        new LaggedGenerator().generate(seed);
    }
}
