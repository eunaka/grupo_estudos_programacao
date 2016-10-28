void *malloc(int);

#define LIST(X) struct List_##X {\
	FIELDS##X(TYPE) \
	struct List_##X *next; \
}; \
struct List_##X *create_list_##X(FIELDS##X(ARG) struct List_##X *next) {\
	struct List_##X *novo = (struct List_##X *)malloc(sizeof(struct List_##X)); \
	FIELDS##X(INIT) \
	novo->next = next; \
	return novo; \
}

#define TYPE(T,N) T N;
#define ARG(T,N) T N,
#define INIT(T,N) novo->N = N;

#define FIELDSPessoa(M) M(char *,nome) M(int,idade)
LIST(Pessoa)

#define FIELDSClass(M) M(char *,aluno) M(int, nota1) M(int, nota2) M(int, notaf) M(int, faltass) 
LIST(Class)

#define FIELDSDisciplina(M) M(char *, nome) M(int, codigo) M(char *,curso) M(int, semestre) M(void *, prerequisitos)
LIST(Disciplina)

/*
gcc -E define.cpp | indent
gcc -E define.cpp | indent | wc -l
cpp define.cpp
gcc -c define.cpp
*/