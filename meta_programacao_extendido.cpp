#1 "meta_programacao.cpp"
#1 "<built-in>"
#1 "<command-line>"
#1 "/usr/include/stdc-predef.h" 1 3 4
#1 "<command-line>" 2
#1 "meta_programacao.cpp"
void *malloc (int);
#19 "meta_programacao.cpp"
struct List_Pessoa
{
  char *nome;
  int idade;
  struct List_Pessoa *next;
};
struct List_Pessoa *
create_list_Pessoa (char *nome, int idade, struct List_Pessoa *next)
{
  struct List_Pessoa *novo =
    (struct List_Pessoa *) malloc (sizeof (struct List_Pessoa));
  novo->nome = nome;
  novo->idade = idade;
  novo->next = next;
  return novo;
}


struct List_Class
{
  char *aluno;
  int nota1;
  int nota2;
  int notaf;
  int faltass;
  struct List_Class *next;
};
struct List_Class *
create_list_Class (char *aluno, int nota1, int nota2, int notaf, int faltass,
		   struct List_Class *next)
{
  struct List_Class *novo =
    (struct List_Class *) malloc (sizeof (struct List_Class));
  novo->aluno = aluno;
  novo->nota1 = nota1;
  novo->nota2 = nota2;
  novo->notaf = notaf;
  novo->faltass = faltass;
  novo->next = next;
  return novo;
}


struct List_Disciplina
{
  char *nome;
  int codigo;
  char *curso;
  int semestre;
  void *prerequisitos;
  struct List_Disciplina *next;
};
struct List_Disciplina *
create_list_Disciplina (char *nome, int codigo, char *curso, int semestre,
			void *prerequisitos, struct List_Disciplina *next)
{
  struct List_Disciplina *novo =
    (struct List_Disciplina *) malloc (sizeof (struct List_Disciplina));
  novo->nome = nome;
  novo->codigo = codigo;
  novo->curso = curso;
  novo->semestre = semestre;
  novo->prerequisitos = prerequisitos;
  novo->next = next;
  return novo;
}
