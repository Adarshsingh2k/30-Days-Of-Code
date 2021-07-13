// function to convert sting in bracket notation to tree

node *makeTree(string s){

	stack<node *>st;

	// root node will be the first element of the string

	node * root= new node(s[0]-'0');

	for(int i=1;i<s.length();i++){

		if(s[i]=='('){
			// if string consist of open bracket 
			// push root element on stack;

			st.push(root);
		}

		else if(s[i]==')'){
			// yahan pe pop the top element
			// and tp element will be now root

			root=st.top();i
			st.pop;
		}


		// if  a number is encountered

		else{

			// ab agar root ka left null hai toh
			// toh number wahan assign hoga nahi toh right mein
			// aur jab assign hojaega toh 
			// we move on left or right of that particular node

			if(root->left==NULL){
				node *lnode= new node(s[i]-'0');
				root->left=root;
				root=root->left;
			}

			else if(root->right==NULL){
				node *rnode= new node(s[i]-'0');
				root->right=rnode;
				root=root->right;
			}

		}

	}

	return root;
}