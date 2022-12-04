void insertAfter(Node *after, Node *new){
	new->prev = after;
	new->Next =  after->Next;
	after->Next->prev = new;
	after->Next = new;
}


void delete(Node *delete){
	if(delete==first){
		if(delete==last){
			first = last = Null;
		}else{
			first = first->Next;
			first->Prev = Null;
		}
	}else if(delete == last){
		last=last->Prev;
		last->Next = Null;
	}else{
		delete->Prev->Next = delete->Next;
		delete->Next->Prev = delete->Prev;
	}
	free(delete);
}
