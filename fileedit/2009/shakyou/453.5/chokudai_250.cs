using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

public class MazeMaker {

    int r, c;
    int[,] board;
    List<int> memo;
    List<int> next;

    public int longestPath(string[] maze, int startRow, int startCol, int[] moveRow, int[] moveCol)
    {
        r = maze.Length;
        c = maze[0].Length;
        board = new int[r, c];
        int i, j;
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (maze[i][j] == '.') board[i, j] = 9999999;
                else board[i, j] = -2;
            }
        }
        board[startRow,startCol] = 0;
        memo = new List<int>();
        memo.Add((startRow << 8) + startCol);
        int res = 1;
        while (memo.Count != 0)
        {
            next = new List<int>();
            foreach (int nextnum in memo)
            {
                int nextr = nextnum >> 8;
                int nextc = nextnum % 256;
                for (i = 0; i < moveCol.Length; i++)
                {
                    int R = nextr + moveRow[i];
                    int C = nextc + moveCol[i];
                    if (ok(R, C))
                    {
                        if (board[R, C] != -2 && board[R, C] > res)
                        {
                            next.Add((R << 8) + C);
                            board[R, C] = res;
                        }
                    }
                }
            }
            //Console.WriteLine(next.Count);
            memo.Clear();
            foreach (int aaa in next) memo.Add(aaa);
            next.Clear();
            res++;
        }
        res = 0;
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                res = Math.Max(res, board[i, j]);
                //if (board[i, j] > 0 && board[i, j] < 10) Console.Write(board[i, j]);
                //else Console.Write("X");
            }
            //Console.WriteLine();
        }
        if (res == 9999999) return -1;
        else return res;
    }

    bool ok(int a, int b)
    {
        return a >= 0 && b >= 0 && a < r && b < c;
    }




} 
