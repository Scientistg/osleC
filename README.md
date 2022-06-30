# Sistemas Embarcados 2022.1

Projeto desenvolvido para a matéria de sistemas embarcados no primeiro semestre de 2022.

Para a construção deste projeto, foram utilizados os seguintes componentes:

 **1.** [Colibri VF50](https://www.toradex.com/pt-br/computer-on-modules/colibri-arm-family/nxp-freescale-vybrid-vf5xx)\
 **2.** [Viola Carrier Board (rev 1.2)](https://www.toradex.com/pt-br/products/carrier-board/viola-carrier-board)\
 **3.** 2 x LED\
 **4.** 3 x PushButton\
 **5.** 2 x Resistores\
 **6.** Fonte de alimentação 5V 1A\

Já para a compilação do projeto foram utilizadas as seguintes dependencias:

 **1.** Ubuntu 20.04\
 **2.** [Toolchain Colibri VF50](https://developer-archives.toradex.com/getting-started/module-2-my-first-hello-world-in-c/configure-toolchain-colibri-vfxx?som=colibri-vf50&board=iris-carrier-board&os=linux&desktop=linux)\
 **3.** [Linux/Yocto Project](https://developer-archives.toradex.com/getting-started/module-1-from-the-box-to-the-shell/update-the-linux-image-iris-carrier-board-colibri-vfxx?som=colibri-vf50&board=iris-carrier-board&os=linux&desktop=linux)



 A seguir, estão descritos os processos de instalação de cada dependência. 

## 1. Ubuntu 20.04
A imagem do sistema operacional **Ubuntu 20.04** pode ser baixada [no site oficial](https://ubuntu.com/).  A instalação de um sistema operacional depende muito do *hardware* em questão e dos demais *softwares* (como outros sistemas operacionais) já instalados. Logo, não será coberto em detalhes neste documento.

Antes de realizar a instalação das demais dependências, recomenda-se atualizar todos os *softwares* do sistema através do comando a seguir.

```console
sudo apt update && sudo apt upgrade
```

## 2. Toolchain Colibri VF50
A **Toolchain Colibri VF50** é utilizada para a realização da compilação cruzada entre o sistema base (**Ubuntu 20.04**) e o sistema embarcado (**Linux/Yocto Project**). Para instalá-la, basta executar os passos descritos neste [tutorial](https://developer-archives.toradex.com/getting-started/module-2-my-first-hello-world-in-c/configure-toolchain-colibri-vfxx?som=colibri-vf50&board=iris-carrier-board&os=linux&desktop=linux). Basta seguir os passos presentes. Caso receba a seguinte mensagem de erro:

> Your environment is misconfigured, you probably need to 'unset LD_LIBRARY_PATH' but please check why this was set in the first place and that it's safe to unset.      The SDK will not operate correctly in most cases when LD_LIBRARY_PATH is set. For more references see: http://tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html#AEN80  http://xahlee.info/UnixResource_dir/_/ldpath.html

Basta executar o seguinte comando: 

```console
unset LD_LIBRARY_PATH
```

## 3. Linux/Yocto Project
O **Linux/Yocto Project** é utilizado como sistema operacional embarcado na placa utilizada. Para instalá-lo, basta executar os passos descritos neste [tutorial](https://developer-archives.toradex.com/getting-started/module-1-from-the-box-to-the-shell/update-the-linux-image-iris-carrier-board-colibri-vfxx?som=colibri-vf50&board=iris-carrier-board&os=linux&desktop=linux). 



## 4. osleC
Para finalizar a instalação, é necessário clonar o pacote no qual está o desenvolvimento deste projeto. Para isso, acesse a pasta de preferência e execute os comandos a seguir.

```console
git clone git@github.com:Scientistg/osleC.git
```

```console
cd osleC
```

Para se realizar a compilação cruzada se executa o seguinte comando:

```console
${CC} -Wall new_code.c -o passaOuRepassa
```

O arquivo **passaOuRepassa** consiste do executável em arquitertura *ARM* que será copiado utilizando ssh. Para isso, deve se conectar a placa em uma rede, obtendo o ip dessa pelo seu metodo de preferência. Com o Host na mesma rede que o sistema embarcado, a fim de facilitar a conexão, realiza-se os seguintes comandos:

```console
scp passaOuRepassa root@<ip>:/home/root
```
Para acessar e executar o projeto:

```console
ssh root@<ip>
```
Dentro do ambiente embarcado:

```console
./passaOuRepassa
```



