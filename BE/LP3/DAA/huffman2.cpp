#include<bits/stdc++.h>

using namespace std;

struct MinHeapNode{
	char data;
	int freq;
	MinHeapNode* left, *right;
	MinHeapNode(char data, int freq){
		left=right=nullptr;
		this->data = data;
		this->freq = freq;
	}
};


void printCodes(struct MinHeapNode* root, string str){
	if(root == nullptr){
		return;
	}
	if(root->data != '$'){
		cout << root->data << ": " << str << endl;
	}
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

struct compare{
	bool operator()(MinHeapNode* a, MinHeapNode* b){
		return (a->freq > b->freq);
	}
};

void HuffmanCode(char data[], int freq[], int size){
	struct 	MinHeapNode *left, *right, *temp;
	
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
	
	for(int i = 0; i < size; i++){
		minHeap.push(new MinHeapNode(data[i], freq[i]));
	}
	
	while(minHeap.size() != 1){
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		temp = new MinHeapNode('$', left->freq + right->freq);
		temp->left = left;
		temp->right = right;
		minHeap.push(temp);
	}
	printCodes(minHeap.top(), "");
}


int main(){
	char data[] = {'A', 'B', 'C', 'D'};
	int freq[] = {3,1,2,1};
	HuffmanCode(data, freq, 4);
	return 0;
}