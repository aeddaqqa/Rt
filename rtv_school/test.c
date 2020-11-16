int      ft_strsplit_len(char **tab)
{
    int     i;

    i = -1;
    while (tab[++i])
        ;
    return (i);
}

int main() 
{
  char  *tab[6];
  tab[0] = "abcd";
  tab[1] = "efgh";
  tab[2] = "ijkl";
  tab[3] = "mnop";
  tab[4] = "qrst";
  tab[5] = "uvwx";
  printf("%d", ft_strsplit_len(tab));
  return 0;
}