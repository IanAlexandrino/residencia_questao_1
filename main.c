#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATOS 20
#define MAX_PARTIDOS 4
#define MAX_NOME 30
#define MAX_NOME_PARTIDO 5

typedef struct {
    char nome[MAX_NOME];
    char partido[MAX_NOME_PARTIDO];
    int votos;
} Candidato;

void pegarNome(Candidato *candidato) {
    printf("Informe o nome do candidato: ");
    scanf("%s", candidato->nome);
}

void pegarPartido(Candidato *candidato) {
    printf("O partido do candidato %s: ", candidato->nome);
    scanf("%s", candidato->partido);
}

void pegarVotos(Candidato *candidato) {
    printf("E por ultimo a quantidade de votos do candidato %s: ", candidato->nome);
    scanf("%d", &candidato->votos);
}

float obterCoeficienteEleitoral(Candidato candidatos[], int numCandidatos) {
    int totalVotos = 0;
    int i;
    
    for (i = 0; i < numCandidatos; i++) {
        totalVotos += candidatos[i].votos;
    }
    return (float)totalVotos / 7; 
}

void obterVotosPorPartido(Candidato candidatos[], int numCandidatos, char partidos[][MAX_NOME_PARTIDO], int votosPorPartido[]) {
	int i;
	
    for (i = 0; i < numCandidatos; i++) {
    	int j;
    	
        for (j = 0; j < MAX_PARTIDOS; j++) {
            if (strcmp(candidatos[i].partido, partidos[j]) == 0) {
                votosPorPartido[j] += candidatos[i].votos;
                break;
            }
        }
    }
}

void imprimirCoeficientesEleitorais(char partidos[][MAX_NOME_PARTIDO], int votosPorPartido[], float coeficientesEleitorais[]) {
    printf("\nCoeficientes Eleitorais:\n");
    int i;
    
    for (i = 0; i < MAX_PARTIDOS; i++) {
        printf("%s: %.2f\n", partidos[i], coeficientesEleitorais[i]);
    }
}

int main() {
    int numCandidatos;
    Candidato candidatos[MAX_CANDIDATOS];
    char partidos[MAX_PARTIDOS][MAX_NOME_PARTIDO];
    int votosPorPartido[MAX_PARTIDOS] = {0};
    float coeficientesEleitorais[MAX_PARTIDOS];

    printf("Informe a quantidade de candidatos (max %d): ", MAX_CANDIDATOS);
    scanf("%d", &numCandidatos);

    if (numCandidatos <= 0 || numCandidatos > MAX_CANDIDATOS) {
        printf("Quantidade invalida.\n");
        return 1;
    }
    int i;
    
    for (i = 0; i < MAX_PARTIDOS; i++) {
        printf("informe o nome do partido %d: ", i + 1);
        scanf("%s", partidos[i]);
    }
    int j;
    
    for (j = 0; j < numCandidatos; j++) {
        pegarNome(&candidatos[j]);
        pegarPartido(&candidatos[j]);
        pegarVotos(&candidatos[j]);
    }

    float coeficienteEleitoral = obterCoeficienteEleitoral(candidatos, numCandidatos);

    obterVotosPorPartido(candidatos, numCandidatos, partidos, votosPorPartido);

    int l;
    
    for (l = 0; l < MAX_PARTIDOS; l++) {
        coeficientesEleitorais[l] = (float)votosPorPartido[l] / coeficienteEleitoral;
    }

    imprimirCoeficientesEleitorais(partidos, votosPorPartido, coeficientesEleitorais);

    int m;
    
    for (m = 0; m < numCandidatos - 1; m++) {
    	int n;
        for (n = 0; n < numCandidatos - m - 1; n++) {
            if (candidatos[n].votos < candidatos[n + 1].votos) {
                Candidato temp = candidatos[n];
                candidatos[n] = candidatos[n + 1];
                candidatos[n + 1] = temp;
            }
        }
    }

    printf("\nCandidatos Eleitos:\n");
    int b;
    
    for (b = 0; b < 7 && b < numCandidatos; b++) {
        printf("%s (%s) - %d votos\n", candidatos[b].nome, candidatos[b].partido, candidatos[b].votos);
    }

    return 0;
}

