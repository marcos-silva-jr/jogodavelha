#include <iostream>
#include <locale> //PARA TODO O TECLADO FICAR NA LÍNGUA PORTUGUESA, PARA ISSO O SETLOCALE, MAS INCLUI ESSA BIBLIOTECA LOCALE
#include <Windows.h> //INCLUDES NECESSÁRIOS PARA EXECUTAR ÁUDIO
#include <MMsystem.h> //INCLUDES NECESSÁRIOS PARA EXECUTAR ÁUDIO
#include <time.h> //NECESSÁRIO PARA CONTAR O TEMPO
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //PARA COR

using namespace std; ///PARA NÃO SER NECESSÁRIO DIGITAR STD::COUT, .. CIN

//VARIÁVEIS

char nomeJogador1[50], nomeJogador2[50]; //GUARDAR NOME DO PRIMEIRO E SEGUNDO JOGADOR COM NO MÁXIMO 50 CARACTERES
int vitoriaJogador1 = 0, vitoriaJogador2 = 0, maquina = 0; //CONTAR VITÓRIAS JOGADOR 1 E JOGADOR 2 E MÁQUINA
int pegandoOpcao, pegandoOpcao2, contraMaquina, quemJogaComAMaquina;  //PARA PEGAR OS NÚMEROS DE 1 A 9 QUE O JOGADOR1 E JOGADOR 2 ESCOLHERÁ
int contarAsVitoriasGeral = 0; //PARA PODER COMEÇAR O JOGO NOVAMENTE, PARA NÃO ENTRAR NO BREAK E ENCERRAR O JOGO
void pause(float); //UM PROTÓPITO TIPO VOID PARA ARMAZENAR FLOAT QUE SERÁ O TEMPO EM QUE O JOGADOR ESPERARÁ

//PARA CONTAR O TEMPO
void pause(float temp) {
	if (temp < 0.001) return;
	float inst1 = 0, inst2 = 0; //DOIS FLOATS CRIADO NESSA FUNÇÃO PARA INICIAR A CONTAGEM NO ZERO
	inst1 = (float)clock() / (float)CLOCKS_PER_SEC;
	while (inst2 - inst1 < temp) inst2 = (float)clock() / (float)CLOCKS_PER_SEC;
}

//INICIAR AS POSIÇÕES DO ZERO :D
int iniciarDoZero(char tabuleiro[3][3]) {
	int zerando; //PARA ZERAR O TABULEIRO
	for (int linha = 0; linha < 3; linha++)
	{
		for (int coluna = 0; coluna < 3; coluna++)
		{
			zerando = tabuleiro[linha][coluna] = 0;   //ZERANDO O TABULEIRO              
		} //FIM DO SEGUNDO FOR
	} //FIM DO PRIMEIRO FOR
	return zerando; //RETORNA A VARIÁVEL QUE É O TABULEIRO COM TODOS VALORES 0                
} // FIM DA FUNÇÃO

//FUNÇÃO PARA PREENCHER O TABULEIRO ATUALIZADO
void tabuleiroAtual(char tabuleiro[3][3]) {
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //COR ALTERADA PARA VERDE
	cout << "\n\t COMO ESTÁ O JOGO ATUALMENTE\n\n";
	cout << "\t_____________________\n\n";
	for (int linha = 0; linha < 3; linha++)
	{
		for (int coluna = 0; coluna < 3; coluna++)
		{
			cout << "\t| " << tabuleiro[linha][coluna] << " |";
		}
		cout << "\n\n";
	}
	cout << "\t_____________________\n\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); //COR ALTERADA PARA BRANCA NOVAMENTE
} //ACABA FUNÇÃO

//PARA IMPRIMIR UMA NOVA JOGADA PARA O JOGADOR 1
void novaJogadaJogador1(char tabuleiro[3][3]) {
	system("cls");
	tabuleiroAtual(tabuleiro);
	int varNovaJogadaJogador1; //PARA GUARDAR NOVA ESCOLHA (JOGADA) DO JOGADOR 1
	cout << "\n\tJÁ ESTÁ PREENCHIDO ESTE CAMPO!\n\tTente outro!\n"
		"\tVocê tem apenas mais ESSA CHANCE ou se não passaremos a vez para o " << nomeJogador2 << " !!\n";
	cout << "\n\t----------------------------\n"
		<< "\t|   1    |    2   |    3   |\n\n"
		<< "\t|   4    |    5   |    6   |\n\n"
		<< "\t|   7    |    8   |    9   |\n"
		<< "\t----------------------------\n";

	//PlaySound(TEXT("audiosWAV/jogadaJogador1.wav"), NULL, SND_SYNC); //ÁUDIO
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //COR ALTERADA PARA VERDE
	cout << "\n\t" << nomeJogador1 << " (Jogador 1) , por favor escolha um número para jogar: \n";
	cin >> varNovaJogadaJogador1; //PEGO O QUE ELE DIGITOU

	switch (varNovaJogadaJogador1) //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
	{
	case 1:    //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[0][0] == 0)
		{
			tabuleiro[0][0] = 'X';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador1 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador2.wav"), NULL, SND_SYNC);
		}
		break;
	case 2:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[0][1] == 0)
		{
			tabuleiro[0][1] = 'X';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador1 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador2.wav"), NULL, SND_SYNC);
		}
		break;
	case 3:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[0][2] == 0)
		{
			tabuleiro[0][2] = 'X';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador1 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador2.wav"), NULL, SND_SYNC);
		}
		break;
	case 4:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[1][0] == 0)
		{
			tabuleiro[1][0] = 'X';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador1 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador2.wav"), NULL, SND_SYNC);
		}
		break;
	case 5:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[1][1] == 0)
		{
			tabuleiro[1][1] = 'X';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador1 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador2.wav"), NULL, SND_SYNC);
		}
		break;
	case 6:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[1][2] == 0)
		{
			tabuleiro[1][2] = 'X';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador1 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador2.wav"), NULL, SND_SYNC);
		}
		break;
	case 7:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[2][0] == 0)
		{
			tabuleiro[2][0] = 'X';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador1 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador2.wav"), NULL, SND_SYNC);
		}
		break;
	case 8:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[2][1] == 0)
		{
			tabuleiro[2][1] = 'X';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador1 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador2.wav"), NULL, SND_SYNC);
		}
		break;
	case 9:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[2][2] == 0)
		{
			tabuleiro[2][2] = 'X';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador1 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador2.wav"), NULL, SND_SYNC);
		}
		break;
	default:
		cout << "\nFim das tentativas, preste mais atenção :)\n";
		//PlaySound(TEXT("audiosWAV/passandoVezParaJogador2.wav"), NULL, SND_SYNC);
		break;
	} //FECHA SWITCH 
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); //COR ALTERADA PARA NORMAL(BRANCA) NOVAMENTE
}

//PARA NOVA JOGADA DO JOGADOR 2 (ÚLTIMA E ÚNICA)
void novaJogadaJogador2(char tabuleiro[3][3]) {
	system("cls");
	tabuleiroAtual(tabuleiro);
	int varNovaJogadaJogador2; //PARA GUARDAR NOVA OPÇÃO DO JOGADOR 2
	cout << "\n\tJÁ ESTÁ PREENCHIDO ESTE CAMPO!\n\tTente outro!\n\tVocê tem apenas mais ESSA CHANCE ou se não passaremos a vez para o " << nomeJogador1 << " !!\n";
	cout << "\n\t----------------------------\n"
		<< "\t|   1    |    2   |    3   |\n\n"
		<< "\t|   4    |    5   |    6   |\n\n"
		<< "\t|   7    |    8   |    9   |\n"
		<< "\t----------------------------\n";

	//PlaySound(TEXT("audiosWAV/jogadaJogador2.wav"), NULL, SND_SYNC); ///ÁUDIO PARA O SEGUNDO JOGADOR
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED); //COR ALTERADA PARA VERMELHO NOVAMENTE
	cout << "\n\t" << nomeJogador2 << " (Jogador 2) , por favor escolha um número para jogar: \n";
	cin >> varNovaJogadaJogador2;

	switch (varNovaJogadaJogador2) //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
	{
	case 1:    //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[0][0] == 0)
		{
			tabuleiro[0][0] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador2 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador1.wav"), NULL, SND_SYNC);
		}
		break;
	case 2:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[0][1] == 0)
		{
			tabuleiro[0][1] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador2 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador1.wav"), NULL, SND_SYNC);
		}
		break;
	case 3:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[0][2] == 0)
		{
			tabuleiro[0][2] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador2 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador1.wav"), NULL, SND_SYNC);
		}
		break;
	case 4:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[1][0] == 0)
		{
			tabuleiro[1][0] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador2 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador1.wav"), NULL, SND_SYNC);
		}
		break;
	case 5:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[1][1] == 0)
		{
			tabuleiro[1][1] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador2 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador1.wav"), NULL, SND_SYNC);
		}
		break;
	case 6:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[1][2] == 0)
		{
			tabuleiro[1][2] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador2 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador1.wav"), NULL, SND_SYNC);
		}
		break;
	case 7:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[2][0] == 0)
		{
			tabuleiro[2][0] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador2 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador1.wav"), NULL, SND_SYNC);
		}
		break;
	case 8:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[2][1] == 0)
		{
			tabuleiro[2][1] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador2 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador1.wav"), NULL, SND_SYNC);
		}
		break;
	case 9:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[2][2] == 0)
		{
			tabuleiro[2][2] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			cout << "Caro(a), " << nomeJogador2 << ", você teve 2 tentativas mas não soube escolher bem, passando a vez :(";
			//PlaySound(TEXT("audiosWAV/passandoVezParaJogador1.wav"), NULL, SND_SYNC);
		}
		break;
	default:
		cout << "\nFim das tentativas, preste mais atenção :)\n";
		//PlaySound(TEXT("audiosWAV/passandoVezParaJogador1.wav"), NULL, SND_SYNC);
		break;
	} //FECHA SWITCH 
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); //COR ALTERADA PARA BRANCA DE NOVO
} //ACABA FUNÇÃO

//JOGADA PARA O JOGADOR 1
void jogadaJogador1(char tabuleiro[3][3]) {
	cout << "\n\t----------------------------\n"
		<< "\t|   1    |    2   |    3   |\n\n"
		<< "\t|   4    |    5   |    6   |\n\n"
		<< "\t|   7    |    8   |    9   |\n"
		<< "\t----------------------------\n";
	//PlaySound(TEXT("audiosWAV/jogadaJogador1.wav"), NULL, SND_SYNC); ///ÁUDIO PARA O PRIMEIRO JOGADOR
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //COR ALTERADA PARA AZUL
	cout << "\n\t" << nomeJogador1 << " (Jogador 1) , por favor escolha um número para jogar: \n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); //COR ALTERADA PARA INTENSIVA NOVAMENTE
	cin >> pegandoOpcao;

	switch (pegandoOpcao)
	{
	case 1:                //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[0][0] == 0)
		{
			tabuleiro[0][0] = 'X';
		}                //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador1(tabuleiro);
		}
		break;
	case 2:                //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[0][1] == 0)
		{
			tabuleiro[0][1] = 'X';
		}                //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador1(tabuleiro);
		}
		break;
	case 3:                //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[0][2] == 0)
		{
			tabuleiro[0][2] = 'X';
		}                //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador1(tabuleiro);
		}
		break;
	case 4:                //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[1][0] == 0)
		{
			tabuleiro[1][0] = 'X';
		}                //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador1(tabuleiro);
		}
		break;
	case 5:                //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[1][1] == 0)
		{
			tabuleiro[1][1] = 'X';
		}                //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador1(tabuleiro);
		}
		break;
	case 6:                //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[1][2] == 0)
		{
			tabuleiro[1][2] = 'X';
		}                //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador1(tabuleiro);
		}
		break;
	case 7:                //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[2][0] == 0)
		{
			tabuleiro[2][0] = 'X';
		}                //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador1(tabuleiro);
		}
		break;
	case 8:                //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[2][1] == 0)
		{
			tabuleiro[2][1] = 'X';
		}                //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador1(tabuleiro);
		}
		break;
	case 9:                //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[2][2] == 0)
		{
			tabuleiro[2][2] = 'X';
		}                //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador1(tabuleiro);
		}
		break;
	default:            //SE NÃO FOR 1 OU 2 OU 3 OU 4 OU 5 OU 6 OU 7 OU 8 OU 9 IMPRIMI ISTO -->
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //COR ALTERADA PARA VERDE
		cout << "\nDigite apenas números de 1 a 9 como mostra no tabuleiro :)\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); //COR ALTERADA PARA INTENSIVA NOVAMENTE
		//PlaySound(TEXT("audiosWAV/apenasNumerosDe1a9.wav"), NULL, SND_SYNC); //E COM ÁUDIO PARA FICAR MAIS DINÂMICO
		novaJogadaJogador1(tabuleiro); //CHAMANDO A NOVA E ÚLTIMA JOGADA PARA O JOGADOR
		break;
	} //FECHA SWITCH
	system("cls");
	tabuleiroAtual(tabuleiro); //CHAMA A FUNÇÃO PARA IMPRIMIR O TABULEIRO
}

//JOGADA PARA O SEGUNDO JOGADOR
void jogadaJogador2(char tabuleiro[3][3]) {
	cout << "\n\t----------------------------\n"
		<< "\t|   1    |    2   |    3   |\n\n"
		<< "\t|   4    |    5   |    6   |\n\n"
		<< "\t|   7    |    8   |    9   |\n"
		<< "\t----------------------------\n";
	//PlaySound(TEXT("audiosWAV/jogadaJogador2.wav"), NULL, SND_SYNC); ///ÁUDIO PARA O SEGUNDO JOGADOR
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED); //COR ALTERADA PARA VERMELHO NOVAMENTE
	cout << "\n\t" << nomeJogador2 << " (Jogador 2) , por favor escolha um número para jogar: \n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); //COR ALTERADA PARA INTENSIVA NOVAMENTE
	cin >> pegandoOpcao2;

	switch (pegandoOpcao2)
	{
	case 1:    //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[0][0] == 0)
		{
			tabuleiro[0][0] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador2(tabuleiro);
		}
		break;
	case 2:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[0][1] == 0)
		{
			tabuleiro[0][1] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador2(tabuleiro);
		}
		break;
	case 3:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[0][2] == 0)
		{
			tabuleiro[0][2] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador2(tabuleiro);
		}
		break;
	case 4:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[1][0] == 0)
		{
			tabuleiro[1][0] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador2(tabuleiro);
		}
		break;
	case 5:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[1][1] == 0)
		{
			tabuleiro[1][1] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador2(tabuleiro);
		}
		break;
	case 6:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[1][2] == 0)
		{
			tabuleiro[1][2] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador2(tabuleiro);
		}
		break;
	case 7:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[2][0] == 0)
		{
			tabuleiro[2][0] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador2(tabuleiro);
		}
		break;
	case 8:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[2][1] == 0)
		{
			tabuleiro[2][1] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador2(tabuleiro);
		}
		break;
	case 9:        //VERIFICA SE ESTÁ VAZIO, CASO SIM, GUARDA NA POSIÇÃO
		if (tabuleiro[2][2] == 0)
		{
			tabuleiro[2][2] = 'O';
		}        //SE NÃO INFORMA QUE JÁ ESTÁ PREENCHIDO O CAMPO
		else
		{
			novaJogadaJogador2(tabuleiro);
		}
		break;
	default:
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED); //COR ALTERADA PARA INTENSIVA NOVAMENTE
		cout << "\nDigite apenas números de 1 a 9 como mostra no tabuleiro :)\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); //COR ALTERADA PARA INTENSIVA NOVAMENTE
		//PlaySound(TEXT("audiosWAV/apenasNumerosDe1a9.wav"), NULL, SND_SYNC);
		novaJogadaJogador2(tabuleiro);
		break;
	} //FECHA SWITCH
	system("cls");
	tabuleiroAtual(tabuleiro);
}

//FUNÇÃO PARA IMPRIMIR O RESULTADO DO JOGO
int resultadoJogoDaVelha(char tabuleiro[3][3]) {
	if (tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X' ///TESTANDO CADA LINHA E COLUNA
		|| tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X'
		|| tabuleiro[0][0] == 'X' && tabuleiro[0][1] == 'X' && tabuleiro[0][2] == 'X'
		|| tabuleiro[1][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 'X'
		|| tabuleiro[2][0] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[2][2] == 'X'
		|| tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X'
		|| tabuleiro[0][1] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X'
		|| tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[2][2] == 'X')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //COR ALTERADA
		cout << "\n\tVITÓRIA DO(A) " << nomeJogador1 << " !! PARABÉNS !!!\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); //COR ALTERADA
	//	PlaySound(TEXT("audiosWAV/jogador1Venceu.wav"), NULL, SND_SYNC);
		system("cls");
		cout << "\nVoltando para o MENU PRINCIPAL, aguarde [..]\n";
		pause(5);
		system("cls");
		vitoriaJogador1++; //CONTANDO UM PONTO PARA O JOGADOR 1       
		contarAsVitoriasGeral++; //PARA MARCAR UM SE O JOGADOR 1 OU 2 VENCERAM, MAS LOGO DEPOIS VIRA 0
	}
	else if (tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O'
		|| tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O'
		|| tabuleiro[0][0] == 'O' && tabuleiro[0][1] == 'O' && tabuleiro[0][2] == 'O'
		|| tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O'
		|| tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 'O'
		|| tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O'
		|| tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O'
		|| tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED); //COR ALTERADA PARA VERMELHO NOVAMENTE
		cout << "\n\tVITÓRIA DO(A) " << nomeJogador2 << " !! PARABÉNS !!!\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); //COR ALTERADA
		//PlaySound(TEXT("audiosWAV/jogador2Venceu.wav"), NULL, SND_SYNC);
		system("cls");
		cout << "\nVoltando para o MENU PRINCIPAL, aguarde [..]\n";
		pause(5);
		system("cls");
		vitoriaJogador2++; //CONTANDO UM PONTO PARA O JOGADOR       
		contarAsVitoriasGeral++; //PARA MARCAR UM SE O JOGADOR 1 OU 2 VENCERAM, MAS LOGO DEPOIS VIRA 0
	}
	else if (tabuleiro[0][0] != 0 && tabuleiro[1][1] != 0 && tabuleiro[2][2] != 0 ///TESTANDO CADA LINHA E COLUNA PARA VER SE DEU VELHA
		&& tabuleiro[0][2] != 0 && tabuleiro[1][1] != 0 && tabuleiro[2][0] != 0
		&& tabuleiro[0][0] != 0 && tabuleiro[0][1] != 0 && tabuleiro[0][2] != 0
		&& tabuleiro[1][0] != 0 && tabuleiro[1][1] != 0 && tabuleiro[1][2] != 0
		&& tabuleiro[2][0] != 0 && tabuleiro[2][1] != 0 && tabuleiro[2][2] != 0
		&& tabuleiro[0][0] != 0 && tabuleiro[1][0] != 0 && tabuleiro[2][0] != 0
		&& tabuleiro[0][1] != 0 && tabuleiro[1][1] != 0 && tabuleiro[2][1] != 0
		&& tabuleiro[0][2] != 0 && tabuleiro[1][2] != 0 && tabuleiro[2][2] != 0)
	{
		cout << "\n\tDeu velha! Que novidade!\n\n";
		//PlaySound(TEXT("audiosWAV/deuVelha.wav"), NULL, SND_SYNC); //	ÁUDIO
		system("cls"); //LIMPA A TELA
		cout << "\nVoltando para o MENU PRINCIPAL, aguarde [..]\n";
		pause(5); //ESPERA 5 SEGUNDOS
		system("cls");
	}
	return 0; //RETORNA 0
}

//FUNÇÃO PARA IMPRIMIR RESULTADO DO JOGO CONTRA A MÁQUINA
int resultadoJogodaVelhaContraMaquina(char tabuleiro[3][3]) {
	if (tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X' ///TESTANDO CADA LINHA E COLUNA
		|| tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X'
		|| tabuleiro[0][0] == 'X' && tabuleiro[0][1] == 'X' && tabuleiro[0][2] == 'X'
		|| tabuleiro[1][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 'X'
		|| tabuleiro[2][0] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[2][2] == 'X'
		|| tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X'
		|| tabuleiro[0][1] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X'
		|| tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[2][2] == 'X')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //COR ALTERADA
		cout << "\n\tVITÓRIA DO(A) " << nomeJogador1 << " !! PARABÉNS !!!\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); //COR ALTERADA
		//PlaySound(TEXT("audiosWAV/jogador1Venceu.wav"), NULL, SND_SYNC);
		system("cls");
		cout << "\nVoltando para o MENU PRINCIPAL, aguarde [..]\n";
		pause(5); //ESPERA 5 SEGUNDOS
		system("cls");
		vitoriaJogador1++; //CONTANDO UM PONTO PARA O JOGADOR 1       
		contarAsVitoriasGeral++; //PARA MARCAR UM SE O JOGADOR 1 OU 2 VENCERAM, MAS LOGO DEPOIS VIRÁ 0
	}
	else if (tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O'
		|| tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O'
		|| tabuleiro[0][0] == 'O' && tabuleiro[0][1] == 'O' && tabuleiro[0][2] == 'O'
		|| tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O'
		|| tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 'O'
		|| tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O'
		|| tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O'
		|| tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O')
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED); //COR ALTERADA PARA VERMELHO NOVAMENTE
		cout << "\n\tVITÓRIA DO(A) " << nomeJogador2 << " !! PARABÉNS !!!\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); //COR ALTERADA
		//PlaySound(TEXT("audiosWAV/jogador2Venceu.wav"), NULL, SND_SYNC);
		system("cls");
		cout << "\nVoltando para o MENU PRINCIPAL, aguarde [..]\n";
		pause(5); //ESPERA 5 SEGUNDOS
		system("cls");
		vitoriaJogador2++; //CONTANDO UM PONTO PARA O JOGADOR       
		contarAsVitoriasGeral++; //PARA MARCAR UM SE O JOGADOR 1 OU 2 VENCERAM, MAS LOGO DEPOIS VIRÁ 0
	}
	else if (tabuleiro[0][0] == 'V' && tabuleiro[1][1] == 'V' && tabuleiro[2][2] == 'V' //VERIFICA SE A MÁQUINA VENCEU
		|| tabuleiro[0][2] == 'V' && tabuleiro[1][1] == 'V' && tabuleiro[2][0] == 'V'
		|| tabuleiro[0][0] == 'V' && tabuleiro[0][1] == 'V' && tabuleiro[0][2] == 'V'
		|| tabuleiro[1][0] == 'V' && tabuleiro[1][1] == 'V' && tabuleiro[1][2] == 'V'
		|| tabuleiro[2][0] == 'V' && tabuleiro[2][1] == 'V' && tabuleiro[2][2] == 'V'
		|| tabuleiro[0][0] == 'V' && tabuleiro[1][0] == 'V' && tabuleiro[2][0] == 'V'
		|| tabuleiro[0][1] == 'V' && tabuleiro[1][1] == 'V' && tabuleiro[2][1] == 'V'
		|| tabuleiro[0][2] == 'V' && tabuleiro[1][2] == 'V' && tabuleiro[2][2] == 'V')
	{
		cout << "\n\tVitória da máquina! ELA É INVENCÍVEL!!\n\nVOCÊEE PERDEEEEEEEU HAHAHAHAH";
		system("cls");
		cout << "\n\tVoltando para o MENU PRINCIPAL, aguarde [..]\n";
		pause(5); //ESPERA 5 SEGUNDOS
		system("cls");
		maquina++; //CONTA PONTOS PARA A MÁQUINA
		contarAsVitoriasGeral++;
	}
	else if (tabuleiro[0][0] != 0 && tabuleiro[1][1] != 0 && tabuleiro[2][2] != 0 ///TESTANDO CADA LINHA E COLUNA PARA VER SE DEU VELHA
		&& tabuleiro[0][2] != 0 && tabuleiro[1][1] != 0 && tabuleiro[2][0] != 0
		&& tabuleiro[0][0] != 0 && tabuleiro[0][1] != 0 && tabuleiro[0][2] != 0
		&& tabuleiro[1][0] != 0 && tabuleiro[1][1] != 0 && tabuleiro[1][2] != 0
		&& tabuleiro[2][0] != 0 && tabuleiro[2][1] != 0 && tabuleiro[2][2] != 0
		&& tabuleiro[0][0] != 0 && tabuleiro[1][0] != 0 && tabuleiro[2][0] != 0
		&& tabuleiro[0][1] != 0 && tabuleiro[1][1] != 0 && tabuleiro[2][1] != 0
		&& tabuleiro[0][2] != 0 && tabuleiro[1][2] != 0 && tabuleiro[2][2] != 0)
	{
		cout << "\n\tDeu velha! Que novidade!\n\n";
		//PlaySound(TEXT("audiosWAV/deuVelha.wav"), NULL, SND_SYNC);
		system("cls");
		cout << "\nVoltando para o MENU PRINCIPAL, aguarde [..]\n";
		pause(5); //ESPERA 5 SEGUNDOS
		system("cls");
	}
	return 0;
}

//FUNÇÃO PARA AS INSTRUÇÕES
void instrucoesFuncao() {
	cout << "\n\t\tINSTRUÇÕES\n\n" << "\t -- JOGO DA VELHA --\n ";
	cout << "\tO jogo da velha é jogado em turnos alternados entre dois jogadores,"
		<< "que serão aqui chamados: " << nomeJogador1 << " e " << nomeJogador2 <<
		". O jogo passa-se num tabuleiro de 3x3 posições nas quais os "
		"jogadores devem marcar uma das posições durante as rodadas. "
		"Escolher um número de 1 A 9 para marcar. O jogador que inicia "
		"a partida utiliza o símbolo “X”, enquanto que o segundo jogador "
		"utiliza o símbolo “O”. Cada jogador é livre para colocar uma "
		"marca em qualquer posição no seu turno, desde que a posição "
		"esteja vazia (sem marcas). Ao colocar uma marca no tabuleiro, "
		"a jogada passa para o próximo jogador, aonde o processo é "
		"repetido até que um dos jogadores vença, ou até o tabuleiro "
		"seja completamente preenchido, situação em que o ocorre empate. "
		"A vitória ocorre quando um jogador consegue colocar três símbolos"
		"em sequência, seja em linha, coluna ou na diagonal principal ou secundária do tabuleiro. \n";

	//PlaySound(TEXT("audiosWAV/instrucoes.wav"), NULL, SND_SYNC); //ÁUDIO PARA INSTRUÇÕES
	pause(30); //TEMPO PARA LER EM 20 SEGUNDOS
	system("cls"); //LIMPAR A TELA LOGO APÓS OS 20 SEGUNDOS
}

//PARA VERIFICAR AS POSIÇÕES E A MÁQUINA JOGAR INTELIGENTEMENTE CONTRA O JOGADOR 1
void maquinaVerificaPosicoesParaJogarContraJogador1(char tabuleiro[3][3]) {
	system("cls");
	tabuleiroAtual(tabuleiro);
	cout << "\nA máquina está pensando! Aguarde um momento, por favor :)\n";
	pause(5); //ESPERA 5 SEGUNDOS
	//VERIFICANDO A PRIMEIRA POSIÇÃO PARA VER SE EU GANHEI
	if (tabuleiro[1][0] == 'V' && tabuleiro[2][0] == 'V' && tabuleiro[0][0] == 0 || tabuleiro[1][1] == 'V'
		&& tabuleiro[2][2] == 'V' && tabuleiro[0][0] == 0 || tabuleiro[0][2] == 'V' && tabuleiro[0][1] == 'V'
		&& tabuleiro[0][0] == 0)
	{
		tabuleiro[0][0] = 'V'; //E O JOGADOR NÃO MARCAR = VAZIO MARCO E VENÇO O JOGO   
	}
	else if (tabuleiro[1][1] == 'V' && tabuleiro[2][1] == 'V' && tabuleiro[0][1] == 0 || tabuleiro[0][0] == 'V'
		&& tabuleiro[0][2] == 'V' && tabuleiro[0][1] == 0) //POSSO VENCER AGORA PELA POSIÇÃO 2 ..
	{
		tabuleiro[0][1] = 'V';  //SE ESTIVER VAZIO EU MARCO
	}
	else if (tabuleiro[1][2] == 'V' && tabuleiro[2][2] && tabuleiro[0][2] == 0 || tabuleiro[1][1] == 'V' &&
		tabuleiro[2][0] == 'V' && tabuleiro[0][2] == 0 || tabuleiro[0][0] == 'V' && tabuleiro[0][1] == 'V' &&
		tabuleiro[0][2] == 0) //POSSIBILIDADE DE EU VENCER (MÁQUINA) VERIFICA PARA 3ª POSIÇÃO
	{
		tabuleiro[0][2] = 'V'; //VENÇO SE ESTIVER VAZIO
	}
	else if (tabuleiro[1][1] == 'V' && tabuleiro[1][2] == 'V' && tabuleiro[1][0] == 0 || tabuleiro[2][0] == 'V'
		&& tabuleiro[0][0] == 'V' && tabuleiro[1][0] == 0) //VERIFICA A POSIÇÃO 4 PARA MIM VENCER
	{
		tabuleiro[1][0] = 'V';
	}
	else if (tabuleiro[1][0] == 'V' && tabuleiro[1][1] == 'V' && tabuleiro[1][2] == 0 || tabuleiro[0][2] == 'V'
		&& tabuleiro[2][2] == 'V' && tabuleiro[1][2] == 0) //VERIFICA PRA MIM PELA 6ª POSIÇÃO
	{
		tabuleiro[1][2] = 'V';
	}
	else if (tabuleiro[0][0] == 'V' && tabuleiro[1][0] == 'V' && tabuleiro[2][0] == 0 || tabuleiro[1][1] == 'V'
		&& tabuleiro[0][2] == 'V' && tabuleiro[2][0] == 0 || tabuleiro[2][1] == 'V' && tabuleiro[2][2] == 'V'
		&& tabuleiro[2][0] == 0) //VERIFICA PRA MÁQUINA PELA 7ª POSIÇÃO
	{
		tabuleiro[2][0] = 'V';
	}
	else if (tabuleiro[1][1] == 'V' && tabuleiro[0][1] == 'V' && tabuleiro[2][1] == 0 || tabuleiro[2][0] == 'V'
		&& tabuleiro[2][2] == 'V' && tabuleiro[2][1] == 0) //PRA MIM GANHAR PELA 8ª POSIÇÃO
	{
		tabuleiro[2][1] = 'V';
	}
	else if (tabuleiro[2][0] == 'V' && tabuleiro[2][1] == 'V' && tabuleiro[2][2] == 0 || tabuleiro[0][0] == 'V'
		&& tabuleiro[1][1] == 'V' && tabuleiro[2][2] == 0 || tabuleiro[0][2] == 'V' && tabuleiro[1][2] == 'V'
		&& tabuleiro[2][2] == 0) //NONA POSIÇÃO para mim GANHAR
	{
		tabuleiro[2][2] = 'V';
	}
	else if (tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X' && tabuleiro[0][0] == 0 || tabuleiro[1][1] == 'X'
		&& tabuleiro[2][2] == 'X' && tabuleiro[0][0] == 0 || tabuleiro[0][2] == 'X' && tabuleiro[0][1] == 'X'
		&& tabuleiro[0][0] == 0) //SE A POSIÇÃO DO JOGADOR 1 FOR "PERIGOSO" PARA MIM (MÁQUINA) DEFENDO ..
	{
		tabuleiro[0][0] = 'V';    //COLOCANDO NA POSIÇÃO SE ESTIVER VAZIA - SE NÃO PASSO PARA O ELSE IF DE BAIXO
	}
	else if (tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[0][1] == 0 || tabuleiro[0][0] == 'X'
		&& tabuleiro[0][2] == 'X' && tabuleiro[0][1] == 0) //OUTRA POSSIBILIDADE DE PERIGO - VERIFICA 2ª POSIÇÃO
	{
		tabuleiro[0][1] = 'V'; //DEFENDO SE ESTIVER VAZIO
	}
	else if (tabuleiro[1][2] == 'X' && tabuleiro[2][2] && tabuleiro[0][2] == 0 || tabuleiro[1][1] == 'X' &&
		tabuleiro[2][0] == 'X' && tabuleiro[0][2] == 0 || tabuleiro[0][0] == 'X' && tabuleiro[0][1] == 'X' &&
		tabuleiro[0][2] == 0) //OUTRA POSSIBILIDADE DE PERIGO - POSIÇÃO 3
	{
		tabuleiro[0][2] = 'V'; //DEFENDO SE ESTIVER VAZIO
	}
	else if (tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[1][0] == 0 || tabuleiro[2][0] == 'X'
		&& tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 0) //VERIFICA A POSIÇÃO 4
	{
		tabuleiro[1][0] = 'V';
	}
	else if (tabuleiro[1][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 0 || tabuleiro[0][2] == 'X'
		&& tabuleiro[2][2] == 'X' && tabuleiro[1][2] == 0) //VERIFICA A POSIÇÃO ( 6 )
	{
		tabuleiro[1][2] = 'V';
	}
	else if (tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 0 || tabuleiro[1][1] == 'X'
		&& tabuleiro[0][2] == 'X' && tabuleiro[2][0] == 0 || tabuleiro[2][1] == 'X' && tabuleiro[2][2] == 'X'
		&& tabuleiro[2][0] == 0) //VERIFICA A POSIÇÃO 7 DO TABULEIRO
	{
		tabuleiro[2][0] = 'V';
	}
	else if (tabuleiro[1][1] == 'X' && tabuleiro[0][1] == 'X' && tabuleiro[2][1] == 0 || tabuleiro[2][0] == 'X'
		&& tabuleiro[2][2] == 'X' && tabuleiro[2][1] == 0) //VERIFICA POSIÇÃO 8
	{
		tabuleiro[2][1] = 'V';
	}
	else if (tabuleiro[2][0] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[2][2] == 0 || tabuleiro[0][0] == 'X'
		&& tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 0 || tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X'
		&& tabuleiro[2][2] == 0) //VERIFICA POSIÇÃO 9 DE PERIGO PARA A MÁQUINA
	{
		tabuleiro[2][2] = 'V';
	}
	else //SE NÃO ATENDER NENHUMA DAS JOGADAS ACIMA VENHO PARA CÁ
	{ //AQUI VERIFICO CADA POSIÇÃO, MENOS A POSIÇÃO 5 QUE JÁ FOI MARCADA ANTERIORMENTE, SE UMA DELAS ESTIVER VAZIA MARCO :D
		if (tabuleiro[0][0] == 0) //VERIFICANDO A POSIÇÃO 1
		{
			tabuleiro[0][0] = 'V';
		}
		else if (tabuleiro[0][1] == 0) //VERIFICANDO POSIÇÃO 2
		{
			tabuleiro[0][1] = 'V';
		}
		else if (tabuleiro[0][2] == 0) //VERIFICANDO POSIÇÃO 3
		{
			tabuleiro[0][2] = 'V';
		}
		else if (tabuleiro[1][0] == 0) //VERIFICANDO POSIÇÃO 4
		{
			tabuleiro[1][0] = 'V';
		}
		else if (tabuleiro[1][2] == 0) //VERIFICANDO POSIÇÃO 6
		{
			tabuleiro[1][2] = 'V';
		}
		else if (tabuleiro[2][0] == 0) //VERIFICANDO POSIÇÃO 7
		{
			tabuleiro[2][0] = 'V';
		}
		else if (tabuleiro[2][1] == 0) //VERIFICANDO POSIÇÃO 8
		{
			tabuleiro[2][1] = 'V';
		}
		else if (tabuleiro[2][2] == 0) //VERIFICANDO POSIÇÃO 9
		{
			tabuleiro[2][2] = 'V';
		}
	}
	system("cls");
	tabuleiroAtual(tabuleiro);
}

//PARA VERIFICAR AS POSIÇÕES E A MÁQUINA JOGAR INTELIGENTEMENTE CONTRA O JOGADOR 2
void maquinaVerificaPosicoesParaJogarContraJogador2(char tabuleiro[3][3]) {
	system("cls");
	tabuleiroAtual(tabuleiro);
	cout << "\nA máquina está pensando! Aguarde um momento, por favor :)\n";
	pause(5); //ESPERA 5 SEGUNDOS
	//VERIFICANDO A PRIMEIRA POSIÇÃO
	if (tabuleiro[1][0] == 'V' && tabuleiro[2][0] == 'V' && tabuleiro[0][0] == 0 || tabuleiro[1][1] == 'V'
		&& tabuleiro[2][2] == 'V' && tabuleiro[0][0] == 0 || tabuleiro[0][2] == 'V' && tabuleiro[0][1] == 'V'
		&& tabuleiro[0][0] == 0)
	{
		tabuleiro[0][0] = 'V'; //E O JOGADOR NÃO MARCAR = VAZIO MARCO E VENÇO O JOGO   
	}
	else if (tabuleiro[1][1] == 'V' && tabuleiro[2][1] == 'V' && tabuleiro[0][1] == 0 || tabuleiro[0][0] == 'V'
		&& tabuleiro[0][2] == 'V' && tabuleiro[0][1] == 0) //POSSO VENCER AGORA ..
	{
		tabuleiro[0][1] = 'V';  //SE ESTIVER VAZIO EU MARCO
	}
	else if (tabuleiro[1][2] == 'V' && tabuleiro[2][2] && tabuleiro[0][2] == 0 || tabuleiro[1][1] == 'V' &&
		tabuleiro[2][0] == 'V' && tabuleiro[0][2] == 0 || tabuleiro[0][0] == 'V' && tabuleiro[0][1] == 'V' &&
		tabuleiro[0][2] == 0) //POSSIBILIDADE DE EU VENCER (MÁQUINA)
	{
		tabuleiro[0][2] = 'V'; //VENÇO SE ESTIVER VAZIO
	}
	else if (tabuleiro[1][1] == 'V' && tabuleiro[1][2] == 'V' && tabuleiro[1][0] == 0 || tabuleiro[2][0] == 'V'
		&& tabuleiro[0][0] == 'V' && tabuleiro[1][0] == 0) //VERIFICA A POSIÇÃO 4 PARA MIM VENCER
	{
		tabuleiro[1][0] = 'V';
	}
	else if (tabuleiro[1][0] == 'V' && tabuleiro[1][1] == 'V' && tabuleiro[1][2] == 0 || tabuleiro[0][2] == 'V'
		&& tabuleiro[2][2] == 'V' && tabuleiro[1][2] == 0) //VERIFICA PRA MIM
	{
		tabuleiro[1][2] = 'V';
	}
	else if (tabuleiro[0][0] == 'V' && tabuleiro[1][0] == 'V' && tabuleiro[2][0] == 0 || tabuleiro[1][1] == 'V'
		&& tabuleiro[0][2] == 'V' && tabuleiro[2][0] == 0 || tabuleiro[2][1] == 'V' && tabuleiro[2][2] == 'V'
		&& tabuleiro[2][0] == 0) //VERIFICA PRA MÁQUINA
	{
		tabuleiro[2][0] = 'V';
	}
	else if (tabuleiro[1][1] == 'V' && tabuleiro[0][1] == 'V' && tabuleiro[2][1] == 0 || tabuleiro[2][0] == 'V'
		&& tabuleiro[2][2] == 'V' && tabuleiro[2][1] == 0) //PRA MIM GANHAR
	{
		tabuleiro[2][1] = 'V';
	}
	else if (tabuleiro[2][0] == 'V' && tabuleiro[2][1] == 'V' && tabuleiro[2][2] == 0 || tabuleiro[0][0] == 'V'
		&& tabuleiro[1][1] == 'V' && tabuleiro[2][2] == 0 || tabuleiro[0][2] == 'V' && tabuleiro[1][2] == 'V'
		&& tabuleiro[2][2] == 0) //NONA POSIÇÃO para mim GANHAR
	{
		tabuleiro[2][2] = 'V';
	}
	else if (tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O' && tabuleiro[0][0] == 0 || tabuleiro[1][1] == 'O'
		&& tabuleiro[2][2] == 'O' && tabuleiro[0][0] == 0 || tabuleiro[0][2] == 'O' && tabuleiro[0][1] == 'O'
		&& tabuleiro[0][0] == 0) //SE A POSIÇÃO DO JOGADOR 1 FOR "PERIGOSO" PARA MIM (MÁQUINA) DEFENDO ..
	{
		tabuleiro[0][0] = 'V';    //COLOCANDO NA POSIÇÃO SE ESTIVER VAZIA - SE NÃO PASSO PARA O ELSE IF DE BAIXO
	} //SE ESTIVER FAVORÁVEL PARA MIM

	else if (tabuleiro[1][2] == 'O' && tabuleiro[2][2] && tabuleiro[0][2] == 0 || tabuleiro[1][1] == 'O' &&
		tabuleiro[2][0] == 'O' && tabuleiro[0][2] == 0 || tabuleiro[0][0] == 'O' && tabuleiro[0][1] == 'O' &&
		tabuleiro[0][2] == 0) //OUTRA POSSIBILIDADE DE PERIGO
	{
		tabuleiro[0][2] = 'V'; //DEFENDO SE ESTIVER VAZIO
	}
	else if (tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[0][1] == 0 || tabuleiro[0][0] == 'O'
		&& tabuleiro[0][2] == 'O' && tabuleiro[0][1] == 0) //OUTRA POSSIBILIDADE DE PERIGO - VERIFICA 2ª POSIÇÃO
	{
		tabuleiro[0][1] = 'V'; //DEFENDO SE ESTIVER VAZIO
	}

	else if (tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[1][0] == 0 || tabuleiro[2][0] == 'O'
		&& tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 0) //VERIFICA A POSIÇÃO 4
	{
		tabuleiro[1][0] = 'V';
	}

	else if (tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 0 || tabuleiro[0][2] == 'O'
		&& tabuleiro[2][2] == 'O' && tabuleiro[1][2] == 0) //VERIFICA A POSIÇÃO ( 6 )
	{
		tabuleiro[1][2] = 'V';
	}

	else if (tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 0 || tabuleiro[1][1] == 'O'
		&& tabuleiro[0][2] == 'O' && tabuleiro[2][0] == 0 || tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 'O'
		&& tabuleiro[2][0] == 0) //VERIFICA A POSIÇÃO 7 DO TABULEIRO
	{
		tabuleiro[2][0] = 'V';
	}

	else if (tabuleiro[1][1] == 'O' && tabuleiro[0][1] == 'O' && tabuleiro[2][1] == 0 || tabuleiro[2][0] == 'O'
		&& tabuleiro[2][2] == 'O' && tabuleiro[2][1] == 0) //VERIFICA POSIÇÃO 8
	{
		tabuleiro[2][1] = 'V';
	}

	else if (tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 0 || tabuleiro[0][0] == 'O'
		&& tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 0 || tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O'
		&& tabuleiro[2][2] == 0) //NONA POSIÇÃO
	{
		tabuleiro[2][2] = 'V';
	}
	else //SE NÃO ATENDER NENHUMA DAS JOGADAS ACIMA VENHO PARA CÁ
	{ //AQUI VERIFICO CADA POSIÇÃO, MENOS A POSIÇÃO 5 QUE JÁ FOI MARCADA ANTERIORMENTE, SE UMA DELAS ESTIVER VAZIA MARCO :D
		if (tabuleiro[0][0] == 0) //VERIFICANDO A POSIÇÃO 1
		{
			tabuleiro[0][0] = 'V';
		}
		else if (tabuleiro[0][1] == 0) //VERIFICANDO POSIÇÃO 2
		{
			tabuleiro[0][1] = 'V';
		}
		else if (tabuleiro[0][2] == 0) //VERIFICANDO POSIÇÃO 3
		{
			tabuleiro[0][2] = 'V';
		}
		else if (tabuleiro[1][0] == 0) //VERIFICANDO POSIÇÃO 4
		{
			tabuleiro[1][0] = 'V';
		}
		else if (tabuleiro[1][2] == 0) //VERIFICANDO POSIÇÃO 6
		{
			tabuleiro[1][2] = 'V';
		}
		else if (tabuleiro[2][0] == 0) //VERIFICANDO POSIÇÃO 7
		{
			tabuleiro[2][0] = 'V';
		}
		else if (tabuleiro[2][1] == 0) //VERIFICANDO POSIÇÃO 8
		{
			tabuleiro[2][1] = 'V';
		}
		else if (tabuleiro[2][2] == 0) //VERIFICANDO POSIÇÃO 9
		{
			tabuleiro[2][2] = 'V';
		}
	}
	system("cls");
	tabuleiroAtual(tabuleiro);
}

int main() {
	setlocale(LC_ALL, "portuguese");

	char tabuleiro[3][3]; //TABULEIRO DO JOGO 3 X 3 - VARIÁVEL DO TIPO CHAR COM UM ARRAY DE 3 POR POSIÇÕES POR 3, OU SEJA (9)

	//PlaySound(TEXT("audiosWAV/digiteSeuNome1.wav"), NULL, SND_SYNC); //ÁUDIO PARA O PRIMEIRO JOGADOR (PARA DIGITAR SEU NOME)
	cout << "Digite o nome para o Jogador 1 ( X ) : \n";
	cin.getline(nomeJogador1, 50);    //RECEBENDO NOME DO PRIMEIRO JOGADOR, EREREEU PEGA 50 CARACTERES
	//PlaySound(TEXT("audiosWAV/simboloJogador1X.wav"), NULL, SND_SYNC); //ÁUDIO PARA O PRIMEIRO JOGADOR

	//PlaySound(TEXT("audiosWAV/digiteSeuNome2.wav"), NULL, SND_SYNC); //ÁUDIO PARA O SEGUNDO JOGADOR DIGITAR SEU NOME
	cout << "Digite o nome para o Jogador 2 ( 0 ) : \n";
	cin.getline(nomeJogador2, 50); //RECEBENDO NOME DO SEGUNDO JOGADOR :DDDD PEGANDO CARACTERES DE NO MÁXIMO 50
	//PlaySound(TEXT("audiosWAV/simboloJogador20.wav"), NULL, SND_SYNC); //ÁUDIO PARA O SEGUNDO JOGADO

	cout << "\n\n\t\t__________________________\n" << "\t\tBEM VINDO AO JOGO DA VELHA\n" ///MENSAGEM PARA OS JOGADORES
		<< "\t\t__________________________\n\n\n" << "\tCaros jogadores " << nomeJogador1 << " & " << nomeJogador2
		<< ", vocês acabaram de entrar no jogo mais divertido e velho do mundo!"
		<< "\n\n\tSIM!" << "\n\n\tÉ O JOGO DA VELHA  !!\n\n";

	//PlaySound(TEXT("audiosWAV/bemVindo.wav"), NULL, SND_SYNC); //ÁUDIO DE BOAS VINDAS AO JOGO :)
	cout << "\n\tRedirecionando para as opções, só um momento :)\n";

	pause(10); //ESPERANDO 10 SEGUNDOS PARA "ENROLAR" JOGADORES
	system("cls"); //LOGO APÓS LIMPO A TELA COM O "CLS"

	int opcaoMenu; /*VARIÁVEL PARA RECEBER O QUE O JOGADOR IRÁ DIGITAR, LOGO DEPOIS UM SWITCH BÁSICO
				   PARA TESTAR O QUE ELE DIGITOU*/
	while (true) //E LOGO DEPOIS ENTRO NO DO WHILE PARA REPETIR AS OPÇÕES PARA O JOGADOR
	{
		cout << "\n\t\t"; //PARA NÃO PEGAR A COR VERDE
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN); //AQUI AGORA FICA VERDE
		cout << "1 - Jogar / Jogar novamente ;";
		SetConsoleTextAttribute(hConsole, SET_BACKGROUND_COLOR); //SAI DO FUNDO VERDE     
		cout << "\n\t\t"; //NÃO PEGA COR VERDE
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN); //COR VERDE
		cout << "2 - Instruções ;";
		SetConsoleTextAttribute(hConsole, SET_BACKGROUND_COLOR); //SAI DO FUNDO VERDE
		cout << "\n\t\t"; //NÃO PEGA
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN); //COR VERDE
		cout << "3 - Ver placar do jogo ;";
		SetConsoleTextAttribute(hConsole, SET_BACKGROUND_COLOR); //SAIU FORA
		cout << "\n\t\t"; //NÃO PEGA
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN); //COR VERDE
		cout << "4 - Sair ;";
		SetConsoleTextAttribute(hConsole, SET_BACKGROUND_COLOR); //SAIU DO FUNDO VERDE
		cout << "\n\n"; //NÃO PEGA
		//PlaySound(TEXT("audiosWAV/menu.wav"), NULL, SND_SYNC); //ÁUDIO
		cin >> opcaoMenu; //RECEBENDO OPÇÃO

		switch (opcaoMenu)///SWITCH PARA PEGAR A OPÇÃO DO JOGADOR
		{
		case 1:
			iniciarDoZero(tabuleiro); //ANTES DE MAIS NADA, INICIAR O TABULEIRO COM VALORES 0, CRIEI ESSA FUNÇÃO E CHAMO AQUI :)
			system("cls");
			cout << "\nDigite 1 para jogar (2 jogadores)\n\tou\n\t\tDigite 2 para jogar contra a máquina:\n";
			cin >> contraMaquina;
			if (contraMaquina == 1) //ESSE IF É PARA AS JOGADAS DOS JOGADORES 1 E 2
			{
				jogadaJogador1(tabuleiro); //PRIMEIRA JOGADA
				jogadaJogador2(tabuleiro); //SEGUNDA JOGADA
				jogadaJogador1(tabuleiro); //TERCEIRA JOGADA
				jogadaJogador2(tabuleiro); //QUARTA JOGADA
				jogadaJogador1(tabuleiro); //QUINTA JOGADA - A PARTIR DA QUINTA JOGADA É POSSÍVEL QUE O JOGADOR VENÇA, ENTÃO
				resultadoJogoDaVelha(tabuleiro);/*CHAMO A FUNÇÃO <--------- DO RESULTADO PARA VERIFICAR SE ELE
												VENCEU PREENCHENDO AS LINHAS E COLUNAS A FIM DE SER O VENCEDOR.*/
				if (contarAsVitoriasGeral != 0)
				{
					contarAsVitoriasGeral = 0; //PARA PODER JOGAR NOVAMENTE
					break;
				}
				else
				{
					jogadaJogador2(tabuleiro); //SEXTA JOGADA
					resultadoJogoDaVelha(tabuleiro);//FUNÇÃO PARA MOSTRAR QUEM VENCEU OU SE DEU VELHA
					if (contarAsVitoriasGeral != 0)
					{
						contarAsVitoriasGeral = 0; //PARA PODER JOGAR NOVAMENTE
						break;
					}
					else
					{
						jogadaJogador1(tabuleiro); //SÉTIMA JOGADA
						resultadoJogoDaVelha(tabuleiro);//FUNÇÃO PARA MOSTRAR QUEM VENCEU OU SE DEU VELHA
						if (contarAsVitoriasGeral != 0)
						{
							contarAsVitoriasGeral = 0; //PARA PODER JOGAR NOVAMENTE
							break;
						}
						else
						{
							jogadaJogador2(tabuleiro); //OITAVA JOGADA
							resultadoJogoDaVelha(tabuleiro);//FUNÇÃO PARA MOSTRAR QUEM VENCEU OU SE DEU VELHA
							if (contarAsVitoriasGeral != 0)
							{
								contarAsVitoriasGeral = 0; //PARA PODER JOGAR NOVAMENTE
								break;
							}
							else
							{
								jogadaJogador1(tabuleiro); //NONA JOGADA (ÚLTIMA)
								resultadoJogoDaVelha(tabuleiro);//FUNÇÃO PARA MOSTRAR QUEM VENCEU OU SE DEU VELHA
							} //FECHA ESSE ELSE
						} //FECHA ELSE DA OITAVA JOGADA
					} //FECHA ELSE DA SÉTIMA JOGADA
				} //FIM DO ELSE DA SEXTA JOGADA
			} //FIM DO IF DO JOGO ENTRE 2 JOGADORES
			else if (contraMaquina == 2) //JOGANDO CONTRA A MÁQUINA
			{
				cout << "\nVai encarar jogar contra a máquina?\n\n\t\t"
					<< "1 para o " << nomeJogador1 << " jogar contra a máquina ;\n\t\t"
					<< "2 para o " << nomeJogador2 << " jogar contra a máquina ;\n";
				cin >> quemJogaComAMaquina;
				if (quemJogaComAMaquina == 1) //ESSE IF É PARA O JOGADOR 1 JOGAR CONTRA A MÁQUINA
				{
					system("cls");
					cout << "\nATENÇÃO! A letra da máquina será ( V ).";
					system("cls");
					tabuleiroAtual(tabuleiro);
					cout << "\nA máquina está pensando! Aguarde um momento, por favor :)\n";
					pause(4); //ESPERA 4 SEGUNDOS
					tabuleiro[1][1] = 'V'; //PRIMEIRA JOGADA DO JOGO, MÁQUINA SEMPRE JOGA NA POSIÇÃO 5
					system("cls");
					tabuleiroAtual(tabuleiro);
					jogadaJogador1(tabuleiro); //SEGUNDA JOGADA
					maquinaVerificaPosicoesParaJogarContraJogador1(tabuleiro); //TERCEIRA JOGADA
					jogadaJogador1(tabuleiro); //QUARTA JOGADA
					maquinaVerificaPosicoesParaJogarContraJogador1(tabuleiro); //QUINTA JOGADA - A PARTIR DA QUINTA JOGADA É POSSÍVEL QUE O JOGADOR VENÇA, ENTÃO
					resultadoJogodaVelhaContraMaquina(tabuleiro);/*CHAMO A FUNÇÃO <--------- DO RESULTADO PARA VERIFICAR SE ELE
																 VENCEU PREENCHENDO AS LINHAS E COLUNAS A FIM DE SER O VENCEDOR.*/
					if (contarAsVitoriasGeral != 0 )
					{
						contarAsVitoriasGeral = 0; //PARA PODER JOGAR NOVAMENTE
						break;
					}
					else
					{
						jogadaJogador1(tabuleiro); //SEXTA JOGADA
						resultadoJogodaVelhaContraMaquina(tabuleiro);//FUNÇÃO PARA MOSTRAR QUEM VENCEU OU SE DEU VELHA
						if (contarAsVitoriasGeral != 0 )
						{
							contarAsVitoriasGeral = 0; //PARA PODER JOGAR NOVAMENTE
							break;
						}
						else
						{
							maquinaVerificaPosicoesParaJogarContraJogador1(tabuleiro); //SÉTIMA JOGADA
							resultadoJogodaVelhaContraMaquina(tabuleiro);//FUNÇÃO PARA MOSTRAR QUEM VENCEU OU SE DEU VELHA
							if (contarAsVitoriasGeral != 0 )
							{
								contarAsVitoriasGeral = 0; //PARA PODER JOGAR NOVAMENTE
								break;
							}
							else
							{
								jogadaJogador1(tabuleiro); //OITAVA JOGADA
								resultadoJogodaVelhaContraMaquina(tabuleiro);//FUNÇÃO PARA MOSTRAR QUEM VENCEU OU SE DEU VELHA
								if (contarAsVitoriasGeral != 0)
								{
									contarAsVitoriasGeral = 0; //PARA PODER JOGAR NOVAMENTE
									break;
								}
								else
								{
									maquinaVerificaPosicoesParaJogarContraJogador1(tabuleiro); //NONA JOGADA (ÚLTIMA)
									resultadoJogodaVelhaContraMaquina(tabuleiro);//FUNÇÃO PARA MOSTRAR QUEM VENCEU OU SE DEU VELHA
								} //FECHA ESSE ELSE
							} //FECHA ELSE DA OITAVA JOGADA
						} //FECHA ELSE DA SÉTIMA JOGADA
					} //FIM DO ELSE DA SEXTA JOGADA
				} //FIM DO IF PARA O JOGO DO JOGADOR 1 CONTRA A MÁQUINA
				else if (quemJogaComAMaquina == 2) //AQUI É A MÁQUINA CONTRA O JOGADOR 2 :))))
				{
					system("cls");
					cout << "\nATENÇÃO! A letra da máquina será ( V ).";
					system("cls");
					tabuleiroAtual(tabuleiro);
					cout << "\nA máquina está pensando! Aguarde um momento, por favor :)\n";
					pause(4); //ESPERA 4 SEGUNDOS
					tabuleiro[1][1] = 'V'; //PRIMEIRA JOGADA DO JOGO, MÁQUINA SEMPRE JOGA NA POSIÇÃO 5
					system("cls");
					tabuleiroAtual(tabuleiro);
					jogadaJogador2(tabuleiro); //SEGUNDA JOGADA
					maquinaVerificaPosicoesParaJogarContraJogador2(tabuleiro); //TERCEIRA JOGADA
					jogadaJogador2(tabuleiro); //QUARTA JOGADA
					maquinaVerificaPosicoesParaJogarContraJogador2(tabuleiro); //QUINTA JOGADA - A PARTIR DA QUINTA JOGADA É POSSÍVEL QUE O JOGADOR VENÇA, ENTÃO
					resultadoJogodaVelhaContraMaquina(tabuleiro);/*CHAMO A FUNÇÃO <--------- DO RESULTADO PARA VERIFICAR SE ELE
																 VENCEU PREENCHENDO AS LINHAS E COLUNAS A FIM DE SER O VENCEDOR.*/
					if (contarAsVitoriasGeral != 0 )
					{
						contarAsVitoriasGeral = 0; //PARA PODER JOGAR NOVAMENTE
						break;
					}
					else
					{
						jogadaJogador2(tabuleiro); //SEXTA JOGADA
						resultadoJogodaVelhaContraMaquina(tabuleiro);//FUNÇÃO PARA MOSTRAR QUEM VENCEU OU SE DEU VELHA
						if (contarAsVitoriasGeral != 0)
						{
							contarAsVitoriasGeral = 0; //PARA PODER JOGAR NOVAMENTE
							break;
						}
						else
						{
							maquinaVerificaPosicoesParaJogarContraJogador2(tabuleiro); //SÉTIMA JOGADA
							resultadoJogodaVelhaContraMaquina(tabuleiro);//FUNÇÃO PARA MOSTRAR QUEM VENCEU OU SE DEU VELHA
							if (contarAsVitoriasGeral != 0)
							{
								contarAsVitoriasGeral = 0; //PARA PODER JOGAR NOVAMENTE
								break;
							}
							else
							{
								jogadaJogador2(tabuleiro); //OITAVA JOGADA
								resultadoJogodaVelhaContraMaquina(tabuleiro);//FUNÇÃO PARA MOSTRAR QUEM VENCEU OU SE DEU VELHA
								if (contarAsVitoriasGeral != 0)
								{
									contarAsVitoriasGeral = 0; //PARA PODER JOGAR NOVAMENTE
									break;
								}
								else
								{
									maquinaVerificaPosicoesParaJogarContraJogador2(tabuleiro); //NONA JOGADA (ÚLTIMA)
									resultadoJogodaVelhaContraMaquina(tabuleiro);//FUNÇÃO PARA MOSTRAR QUEM VENCEU OU SE DEU VELHA
								} //FECHA ESSE ELSE
							} //FECHA ELSE DA OITAVA JOGADA
						} //FECHA ELSE DA SÉTIMA JOGADA
					} //FIM DO ELSE DA SEXTA JOGADA
				} //FIM DO IF PARA O JOGO DO JOGADOR 1 CONTRA A MÁQUINA
			} //FIM DO ELSE IF DO JOGO DA MÁQUINA CONTRA O JOGADOR 2
			else
			{
				cout << "\n\tDígito incorreto! Fique mais atento!\n";
			}
			break;
		case 2:
			instrucoesFuncao();  ///CHAMA A FUNÇÃO PARA AS INSTRUÇÕES
			break;
		case 3:
			cout << "\n\t_________________________\n" << "\n\t *---- PLACAR ATUAL ----*\n\n";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //COR ALTERADA PARA AZUL
			cout << "\t" << nomeJogador1 << " --- " << vitoriaJogador1 << "\n";
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); //COR ALTERADA PARA INTENSIVA NOVAMENTE
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED); //COR ALTERADA PARA VERMELHO NOVAMENTE
			cout << "\n\t" << nomeJogador2 << " --- " << vitoriaJogador2 << "\n";
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); //COR ALTERADA PARA INTENSIVA NOVAMENTE
			cout << "\n\t" << "Máquina" << " --- " << maquina << "\n";
			cout << "\n\t_________________________\n";
			//PlaySound(TEXT("audiosWAV/placarAtual.wav"), NULL, SND_SYNC); //ÁUDIO PARA O PLACAR ATUAL
			break;
		case 4:
			//PlaySound(TEXT("audiosWAV/sair.wav"), NULL, SND_SYNC); //ÁUDIO PARA O FIM
			cout << "\n SAINDO [..] [..]\n" << "Em 5";

			pause(1); //1 SEGUNDO
			system("cls"); //LIMPAR A TELA         
			cout << "4";

			pause(1); //1 SEGUNDO
			system("cls"); //LIMPAR A TELA 
			cout << "3";

			pause(1); //1 SEGUNDO
			system("cls"); //LIMPAR A TELA         
			cout << "2";

			pause(1); //1 SEGUNDO
			system("cls"); //LIMPAR A TELA         
			cout << "1";

			pause(1); //1 SEGUNDO
			system("cls"); //LIMPAR A TELA     
			//PlaySound(TEXT("audiosWAV/adeus.wav"), NULL, SND_SYNC);

			exit(0); ///FUNÇÃO EXIT PARA ENCERRAR O SOFTWARE, OU PROGRAMA, TANTO FAZ         
			break;
		default:
			cout << "\nDígito incorreto!\nDigite um número válido!\n";
			//PlaySound(TEXT("audiosWAV/validar.wav"), NULL, SND_SYNC);
			break;
		} //FECHA SWITCH
	}
	return 0; //RETORNANDO ZERO DO MAIN PARA ENCERRAR COM SUCESSO
} //FIM DO MAIN
//FIM DO PROGRAMA, GLÓRIA A DEUS!