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

 #define REPITA0(V, C) V = 0; C
 #define REPITA1(V, C) V = 1; C; REPITA0(V, C)
 #define REPITA2(V, C) V = 2; C; REPITA1(V, C)
 #define REPITA3(V, C) V = 3; C; REPITA2(V, C)
 #define REPITA4(V, C) V = 4; C; REPITA3(V, C)
 #define REPITA5(V, C) V = 5; C; REPITA4(V, C)
 #define REPITA6(V, C) V = 6; C; REPITA5(V, C)
 #define REPITA7(V, C) V = 7; C; REPITA6(V, C)
 #define REPITA8(V, C) V = 8; C; REPITA7(V, C)
 #define REPITA9(V, C) V = 9; C; REPITA8(V, C)
 #define REPITA10(V, C) V = 10; C; REPITA9(V, C)

 REPITA10(x, a[x] = 0;)

/*
template<int N>
struct Fib<N> {
   const static int value = Fib<N-1> :: value +
                            Fib<N-2> :: value;
};

struct Fib<0> {
   const static int value = 1;
};

Fib<100> :: value;
*/