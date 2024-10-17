#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{

	int dato;
	Nodo *der;
	Nodo *izq;
};

//Prototipos
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&,int);
void mostrarArbol(Nodo *,int);
bool buscar(Nodo *,int); 
void preOrden(Nodo *); 
void inOrden(Nodo *); 
void elimnar(Nodo *,int);
void elimnarNodo(Nodo *); 
Nodo *arbol = NULL;

int main(){
	menu();
	getch();
	return 0;
}

void menu(){
	string dato;
	int opcion;	
	
	do{
		cout<<"\t :MENU:."<<endl;
		cout<<"1. Insertar un nuevo Nodo"<<endl;
		cout<<"2. Mostrar el arbol completo"<<endl;
		cout<<"3. Buscar un Nodo en el arbol "<<endl;
		cout<<"4. Recorrer el arbol en PreOrden "<<endl;
		cout<<"5. Recorrer el arbol en InOrden "<<endl;
		cout<<"6. Recorrer el arbol en Postorden "<<endl;	
		cout<<"7. Salir"<<endl;
		cin>>opcion;
		
		switch (opcion){
			
		case 1: cout<<"\nDigite un numero: ";
				cin>>dato;
				insertarNodo(arbol,dato);
				cout<<"\n";		
				system("pause");
				break;
				
		case 2: cout<<"\nMosntrando arbol completo \n\n";
				mostrarArbol(arbol,contador);
				cout<<"\n";		
				system("pause");
				break;	
				
		case 3: cout<<"\nDigita el nodo a buscar: \n\n";
				cin>>dato;
				if(buscar(arbol,dato) == true){	
					cout<<"\nElemento "<<dato<<" a sido encontrado en el arbol\n";
				}
				else{
					cout<<"\nElemento no contrado en el arbol\n";
				}
				cout<<"\n";			
				system("pause");
				break;	
				
		case 4: cout<<"\nRecorrido en PreOrden:";
				preOrden(arbol);
				cout<<"\n\n";
				system("pause");
				break;
		
		case 5: cout<<"\nRecorrido en InOrden:";
				inOrden(arbol);
				cout<<"\n\n";
				system("pause");
				break;
				
		case 6: cout<<"\nRecorrido en PostOrden:";
				PostOrden(arbol);
				cout<<"\n\n";
				system("pause");
				break;	
				
		case 7: cout<<"\nDigite el numero a eliminar: ";
			}
			
		system("cls");
		
	}while(opcion != 8);
	
}

//creacion del nodo 
Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
}
//funcionnes para insertar el nodo en el arbol

void insertarNodo(Nodo *&arbol,int n){
	
	if(arbol == NULL){ //Validar que el arbol esta vacio
	Nodo *nuevo_nodo = crearNodo(n);
	arbol = nuevo_nodo; //Raiz del arbol
	}
	else{//arbol con datos o nodo
	int valorRaiz = arbol ->dato; //obtener el valor d ela raiz
	if(n < valorRaiz){ // elemento menro que la raiz
		insertarNodo(arbol->izq,n);
	}
	else{//si el elemento de la raiz es mayor, insertar en la derecha
		insertarNodo(arbol->der,n);
	}
}
}

//funciones  para ver los nodos del arbol

void mostrarArbol(Nodo *arbol,int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"		";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}

//funcion correspodiente a la busqueda de un nodo del arbol
bool buscar(Nodo *arbol,int n){
	if(arbol == NULL){ //si el arbol esta vacio
	return false;
	}
	else if(arbol->dato ==n){ //si el nodo es igual al elemento
	return true;
	}
	else if(n < arbol->dato){
		return buscar(arbol->izq,n);
	}
	else{
		return buscar(arbol->der,n);
	}
}

//funcion para recorrido del arbol
void preOrden(Nodo *arbol){
	if (arbol == NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

//funcion para recorrido InOrden
void inOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->der);
	}	
}

//funcion recorriendo en PostOrden

void postOden(Nodo *arbol){
	if(arol == NULL){
		return;
	}
	else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
}

//
void elminar(Nodo *arbol,int n){
	if(arbol == NULL){ //El arbol esta vacio
	return;//No se hace nada
	}
	else if (n < arbol->dato){//Si el valor es menor
	eliminar(arbol->izq,n);//Busca por la Izquierda
	}
	else if (n < arbol->dato){//Si el valor es mayor
	eliminar(arbol->der,n);//Busca  el elemento por la Derecha
	}
	else{//Elemento encontrado
	eliminacionNodo(arbol);
	}







