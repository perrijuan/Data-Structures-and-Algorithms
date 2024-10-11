//algoritimo de busca por profundidade usando dfs 
search(l,t):
//caso base 
se l = null
ret 0

//caso para node>1 
enquanto l != null faça:
lq=search(l.esquerda)
ls=search(l.direita)

ret t=max(lq,ls)+1


//algotimo 2 

Escreva um algoritmo eficiente que preencha, para cada nó da árvore o
campo soma, que deve conter a soma de todas as chaves que estão na subárvore com
aquela raiz.

search_abb(l,x):
se l = x.chave ou l = null
ret 0 
 
h1 = ret search_abb(l.esq, x)
se nao
h2 = ret search_abb (l.dir, x)

ret h1+h2+1 

//algoritimo 3 

Qual a altura máxima de uma árvore binária com n nós?

altura_abb(L, x):

se l = null:
ret 0
se l = x..chave:
ret 1

enquanto l < x.chave :
arv.esq = ret(l.esq)
se nao 
arv.dir = ret (l.dir)

ret max (arv.esq, arv.dir)+ 1 

//algoritimo 4 

escreva um algoritimo eficiente para o procedimento select(k) que torna a k-esima menor chave da arvore, seu procedimento deve utilizar o campo numdesc
faça em pseudo-codigo



//algoritimo 5 

faça a inserção na arvore binaria 


inserir_abb(l,x):

se l !=null:

ret new l e new chave 

se l.valor < x.chave :
l.esq = inserir_abb(l.esq,x)
se nao 
l.dir= inserir_abb(l.dir,x)

ret l 


fim se 

soma_ esq = 0 

se l.esq != null:

soma_esq = l.esq

soma_dir = 0

enquanto l.dir != null

soma_dir = l.dir 

l.soma = l.chave + soma_dir + soma_esq

ret l 



//algoritimo 6 

outra forma de se fazer 

insere_arvore(l,x):
se ll = null:
ret new L

se l.valor < x.chave:

l.esq <- insere_arvore(l.esq, x)

se nao 

l.dir<- insere_arvore(l.dir, x)

soma = l.valor + l.esq + l.dir 

ret soma 

2- Considere uma árvore binaria de busca com raiz apontada por ptraiz, onde cada
nó contém campos esq, dir, chave e soma;
2.1- Escreva um algoritmo eficiente que preencha, para cada nó da árvore o
campo soma, que deve conter a soma de todas as chaves que estão na subárvore com
aquela raiz.

v.chave
se v.chave != null:
faca
esq = funcao_recursiva(v.esq)
dir=funcao_recursova(v.dir)
soma = esq+dir+1
ret soma


2.2 inserção na arvore binaria 

insert_abb(v, chave):

//caso base 
se v.valor = null ou v.valor = chave 
ret new v.valor e new chave 


se v.valor < chave:
v.esq = inserir_abb(v.esq, chave)
se nao :
v.dir = inserir_abb(v.dir, chave)

se v.dir != null entao:
 soma_dir = v.valor + soma.dir + soma.esq 

se v.esq != null entao: 
 soma_esq = v.valor + soma.dir + soma.esq 


 ret soma_dir + soma_esq + 1 


