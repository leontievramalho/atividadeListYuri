#include <iostream>
using namespace std;

struct no {
		int data;
		no* next;
	};

int contarNum(no *&head, int num){
	no *atual = head;
	int cont = 0;
	while(atual != NULL){
		if(atual -> data == num){
			cont ++;
		}
		atual = atual -> next;
	}
	return cont;
}

void reverterTrecho(no *&head, int inicio, int fim){
	int totalElementos = 0;
	no* aux = head;
	while(aux != NULL){
		aux = aux -> next;
		totalElementos++;
	}
	while(totalElementos > 1){
		no* aux = head;
		for(int i = 0; i < totalElementos - 1; i++){
			aux = aux -> next;
		}
		no* anterior = head;
		for(int i = 0; i < totalElementos - 2; i++){
			anterior = anterior -> next;
		}
		aux -> next = anterior;
		totalElementos --;
	}
}

int buscaBinaria(no *head, int inicio, int num){
	if(head != NULL && (head -> next != NULL || head -> data == num)){
		no *atual = head;
		int fim = inicio - 1;
		while(atual != NULL){
			fim ++;
			atual = atual -> next;
		}
		atual = head;
		int meio = (inicio + fim)/2;
		for(int i = inicio; i < meio; i++){
			atual = atual -> next;
		}
		if(atual -> data == num){
			return meio;
		} else if(atual -> data > num){
			atual -> next = NULL;
			buscaBinaria(head, 0, num);
		} else{
			buscaBinaria(atual -> next, meio + 1, num);
		}
	} else{
		return -1;
	}
}

bool isPalindromo(no *&head){
	no *atual = head;
	int fim = 0;
	while(atual -> next != NULL){
		fim ++;
		atual = atual -> next;
	}
	no *noEsq = head;
	no *noDir = atual;
	int meio = (0 + fim)/2;
	if(fim%2 != 0){
		meio ++;
	}
	for(int i = 0; i < meio; i++){
		cout << "noEsq: " << noEsq -> data << endl;
		cout << "noDir: " << noDir -> data << endl;
		if(noEsq -> data != noDir -> data){
			return false;
		}
		noEsq = noEsq -> next;
		noDir = head;
		for(int j = 1; j < fim - i; j++){
			noDir = noDir -> next;
		}
	}
	return true;
}	

void printList(no *&head){
	no *p = head;
	cout << "[";
	while(p != NULL){
		cout << " " << p -> data << " ";
		p = p -> next;
	}
	cout << "]" << endl;
}

int main(int argc, char** argv) {
	
	//lista
	no* head = new no;
	head -> data = 3;
	head -> next = NULL;
	
	no* novoNo = new no;
	novoNo -> data = 5;
	novoNo -> next = NULL;
	head -> next = novoNo;
	
	no* novoNo2 = new no;
	novoNo2 -> data = 5;
	novoNo2 -> next = NULL;
	novoNo -> next = novoNo2;
	
	no* novoNo3 = new no;
	novoNo3 -> data = 3;
	novoNo3 -> next = NULL;
	novoNo2 -> next = novoNo3;
	
	// chamando metodos
	printList(head);
	
	cout << "contando quantas vezes aparece o 3: " << contarNum(head, 3) << endl;
	
	cout << "busca binaria pelo 5 (aparece na posicao): " << buscaBinaria(head, 0, 5) << endl;
	
	printList(head);
	
	if(isPalindromo(head)){
		cout << "e Palindromo." << endl;
	}else{
		cout << "nao e Palindromo.";
	}
	
	//reverterTrecho(head, 1, 3);
	
	printList(head);
	return 0;
}
