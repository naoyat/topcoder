//
// memset
void* memset(void *buf, int ch, size_t n);
// buf の先頭から n バイト分 ch をセットします。
foo(){
  char str[] = "0123456789";
  memset(str+2, '*', 5);
  printf("%s\n",str); // 01*****789
}

void *memcpy(void *buf1, const void *buf2, size_t n);
// buf2 の先頭から n 文字分を、buf1へコピーします。このとき、strcpy()と異なり空文字('\0')を付加することはありません。また、buf2 を単なるメモリブロックとして扱うため、途中に空文字('\0')を含んでいてもコピーを続けます。
// buf1 と buf2 が重なっているときの動作は未定義です。この場合、memmove() では正しくコピーが行われます。

void *memmove(void *buf1, const void *buf2, size_t n);
// buf1 と buf2 が重なっているときの動作は memcpy() では未定義ですが、このmemmove() では正しくコピー（つまり移動）が行われます。
bar() {
  char str[] = "abcdefghijklmnopqrstu";
  printf("移動前：%s\n",str); // abcdefghijklmnopqrstu
  memmove(str+5, str, 10);
  printf("移動後：%s\n",str); // abcdeabcdefghijpqrstu
}                             //      ----------

