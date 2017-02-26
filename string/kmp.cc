/*
 * Args:
 *   s[]: string
 * Return:
 *   fail[]: failure function
 */
int fail[N];
void getfail(char s[])
{
  fail[0] = -1;
  int p = -1;
  for (int i = 0; s[i]; i ++) {
    while (p!=-1 && s[i]!=s[p])  p = fail[p];
    fail[i+1] = ++p;
  }
}
