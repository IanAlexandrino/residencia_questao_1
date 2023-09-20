# residencia_questao_1

TOTALIZADOR DE VOTOS PARA DEPUTADO

Faça um programa em C que materialize o Projeto Totalizador de Votos para Deputado, conforme especificado abaixo:
O Projeto Totalizador de Votos para Deputado lê do usuário os votos obtidos por até 20 candidatos, cujos nomes serão informados pelos usuários e armazenados numa matriz, assim como o partido político de cada um (o usuário deve informar o nome do partido e a sigla), armazenados em outra matriz. Nesta eleição, serão admitidos até 4 partidos políticos. Há apenas 7 vagas para deputado no Distrito Federal, e os candidatos serão eleitos de acordo com o coeficiente eleitoral (a razão entre o número total de votos válidos e o número de vagas). O coeficiente obtido por cada partido informará quantos candidatos ocuparão as vagas. Exemplo: Partido A teve 4,0 de coeficiente, o Partido B 2,1 e o Partido C teve 0,9. Nesse exemplo, o Partido A terá direito a indicar os 3 deputados mais votados e o Partido B terá direito a indicar o deputado mais votado. Como só foram preenchidas 6 vagas, a vaga restante será ocupada pelo candidato mais votado do Partido C, pois possui a maior fração decimal neste exemplo. Assim construa funções que:

● Seja o corpo principal do programa, e chame as demais funções construídas, de forma que o programa funcione da forma mais modularizada possível;

● Leia o nome de cada candidato e o retorne (para ser inserido no corpo principal do programa);

● Receba como parâmetro o nome de um candidato, leia do usuário o nome do partido do respectivo candidato e o retorne;

● Receba como parâmetro o nome de um candidato, leia do usuário a quantidade de votos do respectivo candidato e o retorne;

● Receba como parâmetro um vetor com a quantidade de votos de cada candidato, calcule e retorne o coeficiente eleitoral da votação;

● Receba como parâmetros um vetor com a quantidade de votos de cada candidato, um vetor com os partidos de cada candidato calcule e retorne a quantidade de votos de cada partido;

● Receba como parâmetro um vetor com a quantidade de votos de cada partido, calcule e imprima o coeficiente eleitoral obtido por cada partido;

● Receba como parâmetros uma matriz com os nomes de cada candidato, um vetor com a quantidade de votos de cada candidato, um vetor com os partidos de cada candidato, e um vetor com os coeficientes eleitoral de cada partido, calcule e imprima os nomes dos cinco candidatos eleitos.
