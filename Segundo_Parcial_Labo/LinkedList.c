#include"LinkedList.h"

eLinkedList* Ll_newLinkedList(void){
	eLinkedList* newLinkedList;
	newLinkedList=(eLinkedList*)malloc(sizeof(eLinkedList));
	newLinkedList->pFirstNode=NULL;
	newLinkedList->size=0;
	return newLinkedList;
}

int Ll_len(eLinkedList* this){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		retorno=this->size;
	}
	return retorno;
}

Node* GetNode(eLinkedList* this, int nodeIndex){
	Node* aux;
	aux=NULL;
	if(this!=NULL&&nodeIndex>-1&&nodeIndex<Ll_len(this)){
		aux=this->pFirstNode;
		for(int i=0;i<nodeIndex;i++){
			aux=aux->pNetxNode;
		}
	}
	return aux;
}

int AddNode(eLinkedList* this, int nodeIndex, void* pDato){
	int retorno;
	Node* oldNode;
	Node* newNode;
	retorno=ERROR;
	if(this!=NULL&&nodeIndex>-1&&nodeIndex<=Ll_len(this)){
		newNode=(Node*)malloc(sizeof(Node));
		newNode->pElemento=pDato;
		newNode->pNetxNode=NULL;
		if(!nodeIndex){
			this->pFirstNode=newNode;
			this->size++;
			retorno=0;
		}
		else{
			oldNode=GetNode(this,nodeIndex-1);
			oldNode->pNetxNode=newNode;
			this->size++;
			retorno=0;
		}
	}
	return retorno;
}

int Ll_add(eLinkedList* this, void* pDato){
	int index;
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		index=Ll_len(this);
		AddNode(this,index,pDato);
		retorno=0;
	}
	return retorno;
}

void* Ll_get(eLinkedList* this, int index){
	Node* node;
	void* aux;
	aux=NULL;
	if(this!=NULL&&index>-1&&index<Ll_len(this)){
		node=GetNode(this,index);
		aux=node->pElemento;
	}
	return aux;
}

int Ll_set(eLinkedList* this, int index, void* pDato){
	Node* aux;
	int retorno;
	retorno=ERROR;
	if(this!=NULL&&index>-1&&index<Ll_len(this)){
		aux=GetNode(this,index);
		aux->pElemento=pDato;
		retorno=0;
	}
	return retorno;
}

int Ll_remove(eLinkedList* this, int index){
	Node* aux;
	Node* aux2;
	Node* remove;
	int retorno;
	retorno=ERROR;
	if(this!=NULL&&index>-1&&index<Ll_len(this)){
		if(index==0){
			remove=GetNode(this,index);
			aux2=GetNode(this,index+1);
			this->pFirstNode=aux2;
			free(remove);
			this->size--;
			retorno=0;
		}
		else{
			remove=GetNode(this,index);
			aux=GetNode(this,index-1);
			aux2=GetNode(this,index+1);
			aux->pNetxNode=aux2;
			free(remove);
			this->size--;
			retorno=0;
		}
	}
	return retorno;
}

int Ll_clear(eLinkedList* this){
	int retorno;
	int len;
	retorno=ERROR;
	if(this!=NULL){
		len=Ll_len(this);
		for(int i=0;i<len;i++){
			Ll_remove(this,0);
		}
		retorno=0;
	}
	return retorno;
}

int Ll_deleteLinkedList(eLinkedList* this){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		Ll_clear(this);
		free(this);
		retorno=0;
	}
	return retorno;
}

int Ll_indexOf(eLinkedList* this, void* pDato){
	int retorno;
	int len;
	void* thisElement;
	retorno=ERROR;
	if(this!=NULL){
		len=Ll_len(this);
		for(int i=0;i<len;i++){
			thisElement=Ll_get(this,i);
			if(thisElement==pDato){
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int Ll_isEmty(eLinkedList* this){
	int retorno;
	int len;
	retorno=ERROR;
	if(this!=NULL){
		len=Ll_len(this);
		retorno=0;
		if(len){
			retorno=1;
		}
	}
	return retorno;
}

int Ll_push(eLinkedList* this, int index, void* pDato){
	Node* aux;
	Node* newNode;
	newNode=NULL;
	int retorno;
	retorno=ERROR;
	if(this!=NULL&&index>-1&&index<Ll_len(this)){
			aux=GetNode(this,index);
			AddNode(this,index,pDato);
			newNode=GetNode(this,index);
			newNode->pNetxNode=aux;
			retorno=0;
	}
	return retorno;
}

void* Ll_pop(eLinkedList* this, int index){
	void* thisElement;
	if(this!=NULL&&index>-1&&index<Ll_len(this)){
		thisElement=Ll_get(this,index);
		Ll_remove(this,index);
	}
	return thisElement;
}

int Ll_contain(eLinkedList* this, void* pDato){
	void* thisElement;
	int retorno;
	int len;
	retorno=ERROR;
	if(this!=NULL){
		retorno=0;
		len=Ll_len(this);
		for(int i=0;i<len;i++){
			thisElement=Ll_get(this,i);
			if(thisElement==pDato){
				retorno=1;
				break;
			}
		}
	}
	return retorno;
}

int Ll_containsAll(eLinkedList* this, eLinkedList* this2){
	void* aux;
	int len2;
	int retorno;
	retorno=ERROR;
	len2=Ll_len(this2);
	if(this!=NULL&&this2!=NULL&&len2>0){
		retorno=1;
		for(int i=0;i<len2;i++){
			aux=Ll_get(this2,i);
			if(!Ll_contain(this,aux)){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

eLinkedList* Ll_subList(eLinkedList* this, int from, int to){
	eLinkedList* this2;
	void* aux;
	this2=NULL;
	if(this!=NULL&&from>-1&&from<Ll_len(this)&&to>from&&to<Ll_len(this)){
		this2=Ll_newLinkedList();
		for(int i=0;i<to;i++){
			if(i>=from){
				aux=Ll_get(this,i);
				Ll_add(this2,aux);
			}
		}
	}
	return this2;
}

eLinkedList* Ll_clone(eLinkedList* this){
	eLinkedList* this2;
	this2=NULL;
	if(this!=NULL){
		this2=Ll_newLinkedList();
		this2=Ll_subList(this,0,Ll_len(this));
	}
	return this2;
}

int Ll_sort(eLinkedList* this, int(*pFunc)(void*,void*), int order){
	void* aux;
	void* aux2;
	void* aux3;
	int comparacion;
	int ordenado;
	int retorno;
	int len;
	ordenado=0;
	retorno=ERROR;
	len=Ll_len(this);
	if(this!=NULL&&pFunc!=NULL){
		if(order>=1){
			while(!ordenado){
				ordenado=1;
				for(int i=0;i<len-1;i++){
					aux=Ll_get(this,i);
					aux2=Ll_get(this,i+1);
					comparacion=pFunc(aux,aux2);
					if(comparacion>0){
						aux3=aux;
						Ll_set(this,i,aux2);
						Ll_set(this,i+1,aux3);
						ordenado=0;
					}
				}
			}
			retorno=0;
		}
		else{
			while(!ordenado){
				ordenado=1;
				for(int i=0;i<len-1;i++){
					aux=Ll_get(this,i);
					aux2=Ll_get(this,i+1);
					comparacion=pFunc(aux,aux2);
					if(comparacion<0){
						aux3=aux;
						Ll_set(this,i,aux2);
						Ll_set(this,i+1,aux3);
						ordenado=0;
					}
				}
			}
			retorno=0;
		}
	}
	return retorno;
}

eLinkedList* Ll_filter(eLinkedList* this, int(*pFunc)(void*)){
	eLinkedList* this2;
	void* aux;
	int validacion;
	int len;
	this2=NULL;
	if(this!=NULL&&pFunc!=NULL){
		len=Ll_len(this);
		this2=Ll_newLinkedList();
		for(int i=0;i<len;i++){
			aux=Ll_get(this,i);
			validacion=pFunc(aux);
			if(validacion==1){
				Ll_add(this2,aux);
			}
		}

	}
	return this2;
}

eLinkedList* Ll_map(eLinkedList* this, int (*pFunc)(void*)){
	eLinkedList* this2;
	void* aux;
	int validacion;
	int len;
	this2=NULL;
	if(this!=NULL&&pFunc!=NULL){
		len=Ll_len(this);
		this2=Ll_newLinkedList();
		for(int i=0;i<len;i++){
			aux=Ll_get(this,i);
			Ll_add(this2,aux);
			validacion=pFunc(aux);
			if(validacion==0){
				Ll_set(this2,i,aux);
			}
		}

	}
	return this2;
}

int Ll_count(eLinkedList* this, int (*pFunc)(void*)){
	void* elemento;
	int validacion;
	int len;
	int contador;
	contador=ERROR;
	if(this!=NULL&&pFunc!=NULL){
		contador=0;
		len=Ll_len(this);
		for(int i=0;i<len;i++){
			elemento=Ll_get(this,i);
			validacion=pFunc(elemento);
			if(validacion){
				contador++;
			}
		}
	}
	return contador;
}
