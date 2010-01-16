BEGIN {
  cutting = 0;
}

/^\/\/ BEGIN CUT HERE/ {
  cutting = 1; next;
}
/^\/\/ END CUT HERE/ {
  cutting = 0; next;
}
/^\/\// { next; }

(cutting == 0) {
  gsub(/[ \t]*\/\/.*$/,"");
  ## gsub(/printf(.*);/,"");
  if (/^$/) next;
  print
}
