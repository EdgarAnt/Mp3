#include <iostream>
#include <windows.h>
#include <limits>
#define color SetConsoleTextAttribute


using namespace::std;

int readValidNumber(string);

int readValidNumber(string validation)
{
    cout<<validation;
    int x = 0;
    while(!(cin>>x)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"  Favor de insertar solo numeros."<<endl<<"  ";
        cout<<validation;
    }
    return x;
}

struct nodo{
    string artista;
    string cancion;
    string album;
    string tipo;
	int dato;
	nodo* siguiente;
	nodo* atras;
	nodo *show;
} *primero, *ultimo;

void removerPrimero();
void removerUltimo();
void canciones();
void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void desplegarLista();
void ver_lista();
void ascendiente();
void descendiente();

 void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }



int main(){

	int opcion=0;
	int dato=1;
	gotoxy(10,2);
	do
	{
        system("cls");
        ver_lista();
        canciones();
        cout<<" Menu"<<endl;
        cout<<"1) Nueva cancion"<<endl;
        cout<<"2) Adelantar"<<endl;
        cout<<"3) Atras"<<endl;
        cout<<"4) Borrar"<<endl;
        cout<<"5) Ordenar Ascendente"<<endl;
        cout<<"6) Ordenar Descendente"<<endl;
        cout<<"7) Editar Registro"<<endl;
        cout<<"8) Borrar Primera cancion"<<endl;
        cout<<"9) Borrar Ultima cancion"<<endl;
        cout<<"10) Salir"<<endl;
        cout<<"Opcion"<<endl;
        opcion=readValidNumber(" opcion:");
		switch(opcion){
		case 1:
		    cout<<endl;
			insertarNodo();
			cout<<endl;
			system("pause,cls");
			break;
		case 2:
            cout<<"Adelantar Cancion"<<endl;
            cout<<endl<<endl;
            system("pause");
            break;
		case 3:
            cout<<"Atrasar Cancion"<<endl;
            cout<<endl<<endl;
            system("pause");
                break;
		case 4:
		    cout<<"Borrar Cancion"<<endl;
			eliminarNodo();
			system("pause,cls");
			break;
		case 5:
            cout<<"Ordenar Ascendente "<<endl;
            ascendiente();
            cout<<endl;
            system("pause");
            break;
		case 6:
		    cout<<"Ordenar descente"<<endl;
            ascendiente();
            cout<<endl;
            system("pause");
            break;
        case 7:cout<<"Editar Resgistro"<<endl<<endl;
            modificarNodo();
            cout<<endl;
            system("pause");
            break;
        case 8:cout<<"Borrando primera cancion...."<<endl<<endl;
                    removerPrimero();
                    cout<<endl;
                    system("pause");
                    break;
        case 9:cout<<"Borrando u      ltima cancion"<<endl<<endl;
                    removerUltimo();
                    cout<<endl;
                    system("pause");
                    break;
        default:cout<<"Opcion no valida"<<endl;
                    break;
        }
	} while (opcion != 10);

	return 0;
}


void insertarNodo(){
	nodo* nuevo = new nodo();
	cout<<"ID de la cancion: ";
    cin >> nuevo->dato;
	cout << " Ingrese el nombre del artista: ";
	cin >> nuevo->artista;
	cout << " Ingrese el nombre de la cancion: ";
	cin >> nuevo->cancion;
	cout << " Ingrese el album: ";
	cin >> nuevo->album;
	cout << " Ingrese de que tipo es: ";
	cin >> nuevo->tipo;


	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
	}
}

void removerPrimero()
{
    nodo* actual = primero, *anterior=NULL;
    if(primero==NULL){
		cout<<"No hay ninguna cancion"<<endl;
		return;
	}
	if(actual->siguiente==primero&&anterior==NULL)
        {
            primero=NULL;
            free(actual);
            return;

        }
    if(actual==primero)
    {
        anterior=(primero)->atras;
        primero=primero->siguiente;

        anterior->siguiente=primero;
        primero->atras=anterior;
        free(actual);
    }
}

void removerUltimo()
{
    nodo* actual = primero, *anterior=NULL;
    if(primero==NULL){
		cout<<"No hay ninguna cancion"<<endl;
		return;
	}
	while(actual->siguiente!=primero)
        {
            anterior=actual;
            actual= actual->siguiente;

        }
    if(actual->siguiente==primero)
    {
        anterior->siguiente=primero;
        primero->atras=anterior;
        free(actual);
    }
}

void buscarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << "\n Ingrese el dato del nodo a Buscar: "<<endl;
	cin >> nodoBuscado;
	if(primero!=NULL){
		do{

			if(actual->dato == nodoBuscado){
				cout << " El nodo con el dato ( " << nodoBuscado << " ) Encontrado"<<endl;
				encontrado = true;
			}

			actual = actual->siguiente;
		}while(actual!=primero && encontrado != true);
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}

void modificarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << "\n Ingresa el ID de la cancion para Modificar: ";
	cin >> nodoBuscado;
	if(primero!=NULL){
		do{

			if(actual->dato == nodoBuscado){
				cout << "\n El ID se ha encontrado: " << nodoBuscado;
				cout << "\n Ingrese el ID de la cancion: ";
				cin >> actual->dato;
                cout << " Ingrese el nombre del artista: ";
                cin >> actual->artista;
                cout << " Ingrese el nombre de la cancion: ";
                cin >> actual->cancion;
                cout << " Ingrese el album: ";
                cin >> actual->album;
                cout << " Ingrese de que tipo es: ";
                cin >> actual->tipo;
				cout << "\n Se ha Modificado\n\n";
				encontrado = true;
			}

			actual = actual->siguiente;
		}while(actual!=primero && encontrado != true);
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}

void eliminarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << "\n Ingrese el dato del nodo a Buscar para Eliminar: ";
	cin >> nodoBuscado;
	if(primero!=NULL){
		do{

			if(actual->dato == nodoBuscado){
				cout << "\n El nodo con el dato ( " << nodoBuscado << " ) Encontrado";

				if(actual==primero){
					primero = primero->siguiente;
					ultimo->siguiente = primero;
				}else if(actual==ultimo){
					anterior->siguiente = primero;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}

				cout << "\n Nodo Eliminado\n\n";
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguiente;
		}while(actual!=primero && encontrado != true);
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}

void desplegarLista(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
		do{
			cout << "\n " << actual->dato;
			actual = actual->siguiente;
		}while(actual!=primero);
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}
void ver_lista() {
	nodo *actual = new nodo();
	actual = primero;
	if (primero!=NULL) {
		do {
			cout<<endl<<"ID "<<actual->dato<<"\t Cancion: "<<actual->cancion<<"\t Album: "<<actual->album<<"\tArtista: "<<actual->artista<<"\t Tipo: "<<actual->tipo;
			actual = actual -> siguiente;
		} while(actual!=primero);

	}else{
		cout << "Lista de reproduccion vacia!" << endl;
	}

}
void ascendiente(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
		do{
            cout<<endl<<"ID "<<actual->dato<<"\t Cancion: "<<actual->cancion<<"\t Album: "<<actual->album<<"\tArtista: "<<actual->artista<<"\t Tipo: "<<actual->artista;
			actual = actual->siguiente;
		}while(actual!=primero);

	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
}

void canciones(){

    nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
            HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
            color(hConsole, 2);
            gotoxy(19,10);
            cout<<"_________________________________\n";
            color(hConsole, 2);
            gotoxy(19,11);
			cout<<char(179);
            color(hConsole, 7);
			cout<<"\t\tSpotify\t\t    ";
            color(hConsole, 2);
			cout<<char(179);
            gotoxy(19,12);
            cout<<char(179)<<"________________________________"<<char(179);

		do{
            color(hConsole, 2);
            cout<<endl<<"\t\t   ";
            cout<<char(179);
            color(hConsole, 7);
            cout<<actual->cancion<<".mp3\t\t\t    ";
            color(hConsole, 2);
            cout<<char(179);
			actual = actual->siguiente;
		}while(actual!=primero);
}
            HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
            color(hConsole, 2);
			cout<<"\n\t\t   "<<char(179)<<"________________________________"<<char(179)<<endl;
            color(hConsole, 7);


}

void descendiente(){
	nodo* actual = new nodo();
	actual = ultimo;
	if(primero!=NULL){
		do{
			cout<<endl<<"ID "<<actual->dato<<"\t Cancion: "<<actual->cancion<<"\t Album: "<<actual->album<<"\tArtista: "<<actual->artista<<"\t Tipo: "<<actual->artista;
			actual = actual->atras;
		}while(actual!=ultimo);

	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
}
