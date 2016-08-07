#include "common/common.h"
#include <time.h>
#include "structs/header/hashTableDLL.h"
#include "structs/header/hashTableRBT.h"

int main(int argc, char *argv[]){

    if(argc == 1){
        printLn("Estrutura inválida!");
        printLn("Estruturas: dll ou rbt.");
        return 1;
    }

    if(argc == 2){
        printLn("Arquivo inálido!");
        printLn("Informe o caminho de um arquivo válido.");
        return 1;
    }

    if(argc == 3){
        printLn("Tamanho de buffer inválido");
        printLn("Informe um tamanho de buffer válido.");
        return 1;
    }

    int size = atoi(argv[3]);
    if(size <= 0){
        printLn("Tamanho de buffer inválido!");
        printLn("Informe um tamanho de buffer válido.");
        return 1;
    }

    String structName = newString(argv[1]);
    String fileName = newString(argv[2]);

    int *data = (int *) malloc(sizeof(int) * size);
    size = readOutputFile(fileName, data, size);
    long int t = 0;
    int rCode = 0;
    HashTable ht = NULL;
    int htSize = 10;

    char outputFile[255];
    char datetime[100];
    time_t now = time(0);
    strftime (datetime, 100, "%Y-%m-%dT%H:%M:%S", localtime (&now));
    sprintf(outputFile, "output/out-%s-%s_%s.txt", getCStr(structName), argv[3], datetime);

    if(cStrIsEqual(structName, "dll")){

        ht = newHashTableIntDll(htSize);

        t = getMicroTime();
        for(int i = 0; i < size; i++) insertHashTableIntDll(ht, data[i]);
        t = getMicroTime() - t;

        FILE * rbFile;
        rbFile = fopen (outputFile , "w+");
        if (rbFile != NULL){
            fPrintHashTableIntDll(ht, rbFile);
            fclose(rbFile);
        }

        deleteHashTableIntDll(ht);
    }
    else if(cStrIsEqual(structName, "rbt")){

        ht = newHashTableIntRbt(htSize);

        t = getMicroTime();
        for(int i = 0; i < size; i++) insertHashTableIntRbt(ht, data[i]);
        t = getMicroTime() - t;

        FILE * rbFile;
        rbFile = fopen (outputFile , "w+");
        if (rbFile != NULL){
            fPrintHashTableIntRbt(ht, rbFile);
            fclose(rbFile);
        }

        deleteHashTableIntRbt(ht);
    }
    else{
        printLn("Estrutura inválida!");
        printLn("Estruturas: dll ou rbt.");
        rCode = 1;
    }

    if(rCode == 0) printf("%ld", t);

    deleteString(structName);
    deleteString(fileName);
    free(data);
    return rCode;
}
