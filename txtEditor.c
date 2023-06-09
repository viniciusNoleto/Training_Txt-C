#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_LINE_LENGTH 256
#define FILE_NAME "bissex.txt" // Arquivo do manifesto bissexual com 1.000.039 linhas
#define FILE_NEW_NAME "bissex_manifest.txt" // Arquivo renomeado


// Função void que lê o arquivo linha por linha
void line_read_file() {

    FILE *bi_file = fopen(FILE_NAME, "r");

    if (bi_file == NULL){ // Arquivo não pôde ser lido
        printf("Erro: Arquivo '%s' não pôde ser encontrado...\n", FILE_NAME);
        return;
    }


    char buffer[MAX_LINE_LENGTH];

    while (fgets(buffer, MAX_LINE_LENGTH, bi_file)) printf("%s", buffer);


    // Fecha a leitura do arquivo
    fclose(bi_file);

}


// Função void printa uma linha específica
void specific_line(int line) {

    FILE *bi_file = fopen(FILE_NAME, "r");

    if (bi_file == NULL){ // Arquivo não pôde ser lido
        printf("Erro: Arquivo '%s' não pôde ser encontrado...\n", FILE_NAME);
        return;
    }


    char buffer[MAX_LINE_LENGTH];

    // Navega no arquivo
    for (int i = 1; i < line; i++) {
        if (fgets(buffer, MAX_LINE_LENGTH, bi_file) == NULL) { // Verifica se a linha existe
            printf("Linha %d inalcansável.\n", line);
            break;
        }
    }

    // Lê a linha específica
    if (fgets(buffer, MAX_LINE_LENGTH, bi_file) != NULL) printf("Linha %d: %s", line, buffer);
    else printf("Linha %d inalcansável.\n", line);


    // Fecha a leitura do arquivo
    fclose(bi_file);

}


// Função void que renomeia um arquivo de texto
void rename_file() {

    if (rename(FILE_NAME, FILE_NEW_NAME) == -1) { // Printa o erro caso não consiga renomear o arquivo
        printf("Erro ao renomear o arquivo '%s' renomeado para '%s'\n", FILE_NAME, FILE_NEW_NAME);
        return;
    }


    printf("Arquivo '%s' renomeado para '%s'\n", FILE_NAME, FILE_NEW_NAME);

}


// Função void que trunca e deleta um arquivo de texto
void trunc_delete_file() {

    // Trunca o arquivo para 1 byte
    if (truncate(FILE_NEW_NAME, 1) == -1) {
        printf("Erro ao truncar o arquivo '%s'\n", FILE_NEW_NAME);
        return;
    }

    printf("Arquivo '%s' truncado com sucesso.\n", FILE_NEW_NAME); 

    // Deleta o arquivo
    if (remove(FILE_NEW_NAME) == -1) {
        printf("Erro ao excluir o arquivo '%s'\n", FILE_NEW_NAME);
        return;
    }

    printf("Arquivo '%s' excluído\n", FILE_NEW_NAME);

} 

int main() {

    printf("LEITURA DO ARQUIVO COMPLETO: \n\n");
    line_read_file();

    printf("\nLEITURA DE UMA LINHA ESPECÍFICA: \n\n");
    specific_line(3);

    printf("\nRENOMEAR O ARQUIVO: \n\n");
    rename_file();
    
    printf("\nTRUNCAR E DELETAR O ARQUIVO: \n\n");
    trunc_delete_file();

    return 0;
  
}
