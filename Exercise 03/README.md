Considere que uma "palavra" é qualquer string sem espaços. Exemplos de palavras incluem:

    Amor
    W3C
    14.000,318e12
    1+2

Assim, a frase abaixo contém 15 palavras:
O dia 13 de Fevereiro amanheceu com 13,45mm de chuva e 5+1,61 quartos de água.
A palavra mais comum na frase acima é "de".

Neste exercício, você deverá utilizar std::map para implementar um programa que leia uma série de palavras da entrada padrão, e imprima a palavra mais comum. Assuma que a entreda pode ter mais de uma linha e que não haverá empates: toda frase de teste terá somente uma palavra mais comum. Exemplos:

_____________________________
Um dia Um dia um dia um
_____________________________
Palavra mais comum: dia


_____________________________
a b a; b a.
_____________________________
Palavra mais comum: b

Note que no priomeiro exemplo as palavras "Um" e "um" são diferentes. E note que na segunda frase há somente uma ocorrência das palavras "a", "a;", e "a.", pois a pontuação difere uma palavra da outra.

DICA: Use um map que mapeia cada string ao número de vezes que ela aparece no texto.
