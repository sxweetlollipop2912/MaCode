#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 200001

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> p_t;

maxn n, N;
maxa a[maxN], max[maxN];


void Prepare() {
	std::cin >> n;
	N = 0;
}


class Node {
private:
	p_t data;
	Node* left;
	Node* right;
	maxn height;
	maxa maxSecond;

public:
	maxn CalcHeight() {
		return (height = 1 + std::max((left ? left->height : -1), (right ? right->height : -1)));
	}

	maxa CalcMaxSecond() {
		return (maxSecond = std::max(data.second, std::max(left->data.second, right->data.second)));
	}

	Node* RotateRight() {
		if (!left)
			return this;

		Node* cle = left;
		left = cle->right;
		cle->right = this;

		CalcMaxSecond();
		cle->CalcMaxSecond();

		CalcHeight();
		cle->CalcHeight();

		return cle;
	}

	Node* RotateLeft() {
		if (!right)
			return this;

		Node* cri = right;
		right = cri->left;
		cri->left = this;

		CalcMaxSecond();
		cri->CalcMaxSecond();

		CalcHeight();
		cri->CalcHeight();

		return cri;
	}

	Node* Rebalance() {
		// -2: right heavy, 2: left heavy
		int heavy_side = (left ? left->height : -1) - (right ? right->height : -1);

		if (heavy_side >= -1 && heavy_side <= 1)
			return this;

		Node* res;

		if (heavy_side <= -2) {
			Node* cnode = this->right;
			int hsRight = (cnode->left ? cnode->left->height : -1) - (cnode->right ? cnode->right->height : -1);

			if (hsRight <= 0) { // right right
				res = RotateLeft();
			}
			else {              // right left
				right = right->RotateRight();
				res = RotateLeft();
			}
		}
		else {
			Node* cnode = this->left;
			int hsLeft = (cnode->left ? cnode->left->height : -1) - (cnode->right ? cnode->right->height : -1);

			if (hsLeft >= 0) { // left left
				res = RotateRight();
			}
			else {             // left right
				left = left->RotateLeft();
				res = RotateRight();
			}
		}

		return res;
	}

	Node* Insert(p_t val) {
		if (val == data)
			return this;

		if (data < val)
			right = right ? (right->Insert(val)) : (new Node(val));
		else 
			left = left ? (left->Insert(val)) : (new Node(val));

		CalcMaxSecond();
		CalcHeight();
		return Rebalance();
	}

	/*Node* Delete(p_t val) {
		if (data < val && right)
			right = right->Delete(val);
		else if (data < val && left)
			left = left->Delete(val);
		else {
			if (!left) {
				Node* cri = right;
				right = nullptr;
				delete this;
				return cri;
			}
			if (!right) {
				Node* cle = left;
				left = nullptr;
				delete this;
				return cle;
			}
		}


		CalcHeight();
		return Rebalance();
	}*/

	
	Node(p_t data, Node* left = nullptr, Node* right = nullptr)
		: data(data), left(left), right(right), height(std::max(left? left->height : -1, right? right->height : -1) + 1), 
		maxSecond(std::max(data.second, std::max(left ? left->maxSecond : 0, right ? right->maxSecond : 0))) {
	}

	~Node() {
		delete left;
		delete right;
	}
};


int main() {
	std::vector<int>* p;
	{
		std::vector<int>* a = new std::vector<int>(100, 5);
		p = a;
		std::cout << p << " " << (*p)[0] << "\n";

		delete a;
	}
	std::cout << p << " " << (*p)[0] << "\n";
}