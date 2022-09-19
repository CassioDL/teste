void cadastraCli() //cadastro do arquivo produtos
{ char op; //vari�vel op��o
  system("cls");  //limpa tela
  int tamanho=0; // declara��o da vari�veltamanho para capturar a qtdide de registros cadastrdas
  fProdutos = fopen("produtos.dat","r+");//abre o arquivo produtos para leitura e escrita 
  rewind(fProdutos);  //joga para o primeiro registro do arquivo - posi��o 0
  do{ //la�o de repeti��o para contar a qtidade de registros do arquivo
  fread(&Produto,sizeof(Produto),1,fProdutos);//leitura do registro no arquivo
  tamanho++;} //tamanho = tamanho + 1 - Contar qtos registros
  while(!feof(fProdutos)); //fa�a at� o final do arquivo

  fseek(fProdutos,sizeof(Produto),tamanho); //aponta para a posi��o do arquivo correspondente ao tamanho
  do
  {
     system("cls");//limpa tela
     //printf("\n Digite o codigo do produto:");// mostra na tela
     cout<<"\n Digite o codigo do produto:";//cout - comando output - printf
	 cin>>Produto.codprod; //cin  C - comando in  - input  - Comando de entrada - scanf
     printf("\n Digite o nome do produto:");
     cin>>Produto.nomeprod;
     printf("\n Digite o valor unitario do produto:");
     cin>>Produto.valorUniprod;
     tamanho=tamanho+fwrite(&Produto,sizeof(struct dadosProd),1,fProdutos); //gravando o registro no arquivo
     //tamanho recebe incremento para gravar o pr�ximo registro.
     printf("\n Continuar cadastrando <S> ou <N>:");
     cin>>op;//ler a op��o 
     op = toupper(op); //comando que coloca o caracter em ma�usculo 
	 }while(op =='S'); // enquanto op igual S
     fclose(fProdutos);// fecha o arquivo produtos
}

void consultaProd() //lista todos os registros do arquivo Produto
{
     system("cls");//limpa a tela
     fProdutos=fopen("produtos.dat","r"); //Abrir o arquivo produtos para leitura - Consulta
     fseek(fProdutos,sizeof(struct dadosProd),0);//aponta para o registro 0 do arquivo de Produtos

     while(fread(&Produto,sizeof(Produto),1,fProdutos)==1)
      {
	 system("cls");//limpa a tela
	 printf("Codigo Produto:           %d\n",Produto.codprod);// mostra na tela o campo codigo do registro do produto
	 printf("Nome Produto:             %s\n",Produto.nomeprod);
	 printf("Valor unitario Produto:   %.2f\n",Produto.valorUniprod);
	 printf("\n Digite enter para continuar\n");
	 getch();//pedi para teclar algo  - enter
      }
     printf("\n fim do arquivo");
     fclose(fProdutos); //fecha arquivo produtos
     getch(); //espera ser teclado algo para continuar
}

void consulta_codprod(){  //lista o registro selecionado pelo usu�rio do arquivo produto
     //vari�veis locais - somente enxergadas aqui
	 char nom_pro[20]; //vari�vel para o usu�rio digitar o nome do usu�rio a ser pesquisado no arquivo
     int achou=1;  //vari�vel com sinlizador(flag) para indicar que achou o produto e pode listar os dados e parar a pesquisa no arquivo
     int localizou=1;//vari�vel que localizou o produto desejado
     char op; //vari�vel op��o
	 	 
	system("cls"); //limpa a tela
	fProdutos=fopen("produtos.dat","r+"); // abre o arquivo para leitura e escrita
	fseek(fProdutos,sizeof(struct dadosProd),0);//aponta pora o Registro 0(inicial) do arquivo
	printf("\n Digite o Codigo p/ Procura : "); //Pergunta ao usu�rio qual produto deseja buscar na consulta
	cin>>nom_pro;//Us�rio Digita o nome do produto a ser procurado
	       while(fread(&Produto,sizeof(produto),1,fProdutos)==1){//la�o de repeti��o para percorrer registro a registro no arquivo at� localizar o produto desejado
		    achou=strcmp(Produto.codprod,nom_pro);//comando que compara as nome digitado pelo usu�rio com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string codigo do produto do registro (Produto.codprod)
		    //e subtrai do valor hexadecimal dos caracteres da string codigo do produto para ser procurado (nome_pro)
		    //se forem iguais o resultado � zero e � alocado para a vari�vel achou, caso contr�rio vai 1 para a var�avel
			 if(achou==0)
			 { //nomes s�o iguais ent�o achou o cliente desejado
		       printf("\n O Nome �.................:%s",Cliente.nomeCli);//lista o nome do cliente na tela
		       printf("\n A Idade �................:%d",Cliente.idadeCli);//lista a idade do cliente na tela
		       printf("\n O Sal�rio Bruto �........:%0.2f",Cliente.sbaseCli);
		       printf("\n O Valor da Compra �......:%0.2f",Cliente.vcomprasCli);
		       printf("\n_____________________________________________\n");
		       getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		       localizou=0;
		       }}

		if(localizou == 1){ //varreu todo o arquivo e n�o encontrou o nome do cliente para ser consultado
		    printf("\n Cliente n�o Cadastrado\n"); //lista na tela
		    printf("\n Cadastrar Cliente <S> ou <N>:");//lista na tela para pedir se o usu�rio deseja cadastrar este cliente n�o encontrado
		    cin>>op;//l� a op��o do usu�rio em cadastrar ou n�o
		    op = toupper(op);//pega o a caracter S ou N digitado pelo usu�rio e coloca em letra ma�uscula
		    if (op=='S'){ //compara o valor da vari�vel op para cadastrar ou n�o o novo cliente
		    cadastraCli();} //chama a fun��o para cadstrar o novo cliente
			else {fclose(fClientes);} //fecha arquivo clientes
			getch();}}//espera algo a ser teclado e saia da fun��o de consulta cliente pelo nome