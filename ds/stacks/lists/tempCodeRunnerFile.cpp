node * temp = top;
    cout << endl;
    cout << " -- " <<endl;
    while(temp){
      cout <<"| " <<temp->data << " |"<<endl;
      temp=temp->next;
    }
    cout << " -- " <<endl;