#include <iostream>
using namespace std;

struct elem {
    int exp;
    int coe;
    elem* next;
    elem(int a = 0, int b = 0, elem* c = NULL) {
        coe = a;
        exp = b;
        next = c;
    }
};

int main() {
    int m;
    cin >> m;
    while (m--) {
        int p1_num, p2_num;
        int p3_num = 0;
        elem* poly1 = NULL;
		elem* poly2 = NULL;
		elem* poly3 = NULL;
		elem* now = NULL;
        cin >> p1_num;
        int e, c;
        for (int i = 0; i < p1_num; i++) {
            cin >> c >> e;
            if (poly1 == NULL) {
                poly1 = new elem(c, e, NULL);
                now = poly1;
            } else {
                now -> next = new elem(c, e, NULL);
                now = now->next;
            }
        }
        now = NULL;
        cin >> p2_num;
        for (int i = 0; i < p2_num; i++) {
            cin >> c >> e;
            if (poly2 == NULL) {
                poly2 = new elem(c, e, NULL);
                now = poly2;
            } else {
                now -> next = new elem(c, e, NULL);
                now = now->next;
            }
        }
        now = NULL;
        elem* p1 = poly1;
        elem* p2 = poly2;
        if (poly1 == NULL&&poly2 == NULL) {
        	cout << "0" << endl;
        	continue;
        }
        if (poly1 == NULL) {
        	cout << p2_num << endl;
        	while (p2 != NULL) {
        		cout << p2->coe << " " << p2-> exp << endl;
        		p2 = p2->next;
        	}
        } else if (poly2 == NULL) {
        	cout << p1_num << endl;
        	while (p1 != NULL) {
        		cout << p1->coe << " " << p1-> exp << endl;
        		p1 = p1->next;
        	}
        } else {
        	while (1) {
        		if (p1 == NULL&&p2 == NULL) {
        			break;
        		}

        		if (p1 == NULL) {
        			if (poly3 == NULL) {
        				poly3 = new elem(p2->coe, p2->exp, NULL);
        				now = poly3;
        				p3_num++;
        			} else {
        				now->next = new elem(p2->coe, p2->exp, NULL);
        				now = now->next;
        				p3_num++;
        			}
        			p2 = p2->next;
        			continue;
        		}
        		if (p2 == NULL) {
        			if (poly3 == NULL) {
        				poly3 = new elem(p1->coe, p1->exp, NULL);
        				now = poly3;
        				p3_num++;
        			} else {
        				now->next = new elem(p1->coe, p1->exp, NULL);
        				now = now->next;
        				p3_num++;
        			}
        			p1 = p1->next;
        			continue;
        		}

        		if (p1->exp == p2->exp) {
        			if (p1->coe+p2->coe != 0) {
        			if (poly3 == NULL) {
        				poly3 = new elem(p1->coe+p2->coe, p1->exp, NULL);
        				now = poly3;
        				p3_num++;
        			} else {
        				now->next = new elem(p1->coe+p2->coe, p1->exp, NULL);
        				now = now->next;
        				p3_num++;
        			}
        			}
        			p1 = p1->next;
        			p2 = p2->next;
        		} else if (p1->exp > p2->exp) {
        			if (poly3 == NULL) {
        				poly3 = new elem(p1->coe, p1->exp, NULL);
        				now = poly3;
        				p3_num++;
        			} else {
        				now->next = new elem(p1->coe, p1->exp, NULL);
        				now = now->next;
        				p3_num++;
        			}
        			p1 = p1->next;
        		} else {
        			if (poly3 == NULL) {
        				poly3 = new elem(p2->coe, p2->exp, NULL);
        				now = poly3;
        				p3_num++;
        			} else {
        				now->next = new elem(p2->coe, p2->exp, NULL);
        				now = now->next;
        				p3_num++;
        			}
        			p2 = p2->next;
        		}
        	}
        	elem* p3 = poly3;
        	cout << p3_num << endl;
        	while (p3 != NULL) {
        		if (p3->coe == 0) {
        			continue;
        		}
        		cout << p3->coe << " " << p3->exp << endl;
        		p3 = p3->next;
        	}
        }
        while (poly1 != NULL) {
        	elem* temp = poly1;
        	poly1 = poly1->next;
        	delete temp;
        }
        while (poly2 != NULL) {
        	elem* temp = poly2;
        	poly2 = poly2->next;
        	delete temp;
        }
        while (poly3 != NULL) {
        	elem* temp = poly3;
        	poly3 = poly3->next;
        	delete temp;
        }
    }
    return 0;
}
