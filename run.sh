 #!/bin/sh

buildDir="./build/";
outputDir="./output/";

invocation="./tools/compiler";

if [ ! -d "$outputDir" ]; then
  mkdir "$outputDir";
fi

chmod +x $invocation;

function questao5(){
    bash -c "$invocation questao5.c structs/src/linkedList.c structs/src/RBTree.c structs/src/hashTable.c structs/src/hashTableDLL.c structs/src/hashTableRBT.c";
    echo "Executando o programa questao5...";
    echo;
    result=$(bash -c "${buildDir}questao5 $1 $2 $3");
    if [ $? -eq 0 ]; then
        echo "Foram ordenados $3 números em ${result} µs.";
    else
        echo "Erro na execução:";
        echo "$result";
    fi
}

function generate(){
    bash -c "$invocation generate.c";
    echo "Executando o programa generate...";
    bash -c "${buildDir}generate $1 $2 $3";
    echo;
    echo "Foram gerados $1 números e salvos em $2.";
}

case $1 in

    "questao5")
        questao5 "$2" "$3" "$4";
    ;;

    "questao5.")
        questao5 "$2" "$3" "$4";
    ;;

    "questao5.c")
        questao5 "$2" "$3" "$4";
    ;;

    "generate.c")
        generate "$2" "$3" "$4";
    ;;

    "generate.")
        generate "$2" "$3" "$4";
    ;;

    "generate")
        generate "$2" "$3" "$4";
    ;;

 	*)
 		echo "Opções: generate."
 		exit 1;
 	;;
esac

exit 0;
