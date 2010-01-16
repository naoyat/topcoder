main()
{   
  int M, N;
  vector<int> pointX, pointY;
  cin >> M;
  cin >> N;
  rep(i,N) cin >> pointX[i];
  rep(i,N) cin >> pointY[i];

  EnclosingCircles ec;
  vector<string> ret = ec.placeCircles(pointX,pointY,M);
  int s = ret.size();
  cout << s << endl;
  rep(i,s) cout << ret[i] << endl;
}
