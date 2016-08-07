 #!/bin/sh

buildDir="./build/";
outputDir="./output/";

invocation="./tools/compiler";

if [ ! -d "$outputDir" ]; then
  mkdir "$outputDir";
fi

chmod +x $invocation;

case $1 in

    "generate.c")
        bash -c "$invocation generate.c";
        echo "Executando o programa generate...";
        bash -c "${buildDir}generate $2 $3 $4";
        echo;
        echo "Foram gerados $2 números e salvos em $3.";
    ;;

    "generate.")
        bash -c "$invocation generate.c";
        echo "Executando o programa generate...";
        bash -c "${buildDir}generate $2 $3 $4";
        echo;
        echo "Foram gerados $2 números e salvos em $3.";
    ;;

    "generate")
        bash -c "$invocation generate.c";
        echo "Executando o programa generate...";
        bash -c "${buildDir}generate $2 $3 $4";
        echo;
        echo "Foram gerados $2 números e salvos em $3.";
    ;;

 	*)
 		echo "Opções: generate."
 		exit 1;
 	;;
esac

exit 0;
