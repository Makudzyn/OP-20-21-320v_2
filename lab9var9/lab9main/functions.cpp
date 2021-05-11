#include "structs.h"
#include "functions.h"

void menu() {
	printf("��� ������?\n");
	printf("1. ������� ������ \n");
	printf("2. ���������� ������ c ������\n");
	printf("3. ���������� ������ c �����\n");
	printf("4. ����� �� �������� � ������\n");
	printf("5. ����� �� �������� � �����\n");
	printf("6. ���������� �������� \n");
	printf("7. �������� �������� \n");
	printf("8. ���������� \n");
	printf("9. ������ ������ � ���� \n");
	printf("10. �������� ������ ������ �� ����� \n");
	printf("11. ����� �� ��������� \n");
	printf(">> ");
}

void listCreation(Tlist*& head, Tlist*& tail, int& count, int point, int size) {
	if (point == 1) { //�������������
		srand(time(0));

		int random = 0;
		bool checker;
		int* namesArr = new int[size];
		int* producArr = new int[size];

		for (int i = 0; i < size;) { //� ���� ������ ����������� ����� �� 1 �� 10 ������� �� ����� �����������
			random = rand() % 10;
			checker = true;

			for (int j = 0; j < size; j++) {
				if (random == *(namesArr + j))
					checker = false;
			}
			if (checker) {
				*(namesArr + i) = random;
				i++;
			}
		}
		for (int i = 0; i < size;) {
			random = rand() % 10;
			checker = true;

			for (int j = 0; j < size; j++) {
				if (random == *(producArr + j))
					checker = false;
			}
			if (checker) {
				*(producArr + i) = random;
				i++;
			}
		}

		char namesList[][15] = { "Office","SmartSute","pdfReader","Paint","DriverBooster","MemReduct","ImageViewer","Telegram","Torrent","Blender" };
		char producersList[][15] = { "Microsoft","Supercell","IObit","Sun","Oracle","SAP_SG","Symantec","Nintendo","Adobe","E.A" };

		Tlist* tmp = new Tlist;
		head = tail = tmp;

		for (int i = 0; i < size; i++) { //����������
			int tmp1 = *(namesArr + i);
			int tmp2 = *(producArr + i);
			strcpy_s(tmp->data.title, *(namesList + tmp1));
			strcpy_s(tmp->data.producer, *(producersList + tmp1));
			tmp->data.count = rand() % 20 + 1;
			tmp->data.price = rand() % 100 + 100 - 0.5;

			tail->next = tmp;
			tmp->prev = tail;
			tail = tmp;
			tmp = new Tlist;
			tmp->next = NULL; 
			
		}
		Tlist* end = tail;
		for (int i = 0; i != size; i++) {end = end->prev;}
		end->prev = NULL;

		count = size;
		delete[] namesArr;
		delete[] producArr;
	}
	else if (point == 2) { //�������
		Tlist* tmp = new Tlist;
		printf("������� >> \n");
		printf("������������:  "); scanf_s("%s", tmp->data.title, 15);      setbuf(stdin, NULL);
		printf("�������������: "); scanf_s("%s", tmp->data.producer, 10);	setbuf(stdin, NULL);
		printf("���������� �.: "); scanf_s("%d", &tmp->data.count);
		printf("����:          "); scanf_s("%lf", &tmp->data.price);
		head = tail = tmp;
		tmp->prev = NULL;
		tmp->next = NULL;
		count++;
	}
}

void listPrintFromHead(Tlist* head) {
	if (head != NULL) {
		Tlist* tmp;
		tmp = head;
		while (tmp != NULL) {
			printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
			tmp = tmp->next;
		}
		printf("\n");
	}
	else printf("\n������ �������� ������.\n");
}

void listPrintFromTail(Tlist* tail) {
	if (tail != NULL) {
		Tlist* tmp;
		tmp = tail;
		while (tmp != NULL) {
			printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
			tmp = tmp->prev;
		}
		printf("\n");
	}
	else printf("\n������ �������� ������.\n");
}

int searchByParamFromHead(Tlist* head, int count) {
	int point;
	Tlist* tmp;
	Tlist tmpAsk;

	while (true) {
		bool rpt = true;
		tmp = head;
		printf("\n������ ��...\n");
		printf("1. ������������ \n");
		printf("2. ������������� \n");
		printf("3. ���-�� ������ \n");
		printf("4. ���� \n");
		printf("5. �����\n");
		printf(">> "); scanf_s("%d", &point);

		switch (point) {
		case 1:
			printf("������������ > "); scanf_s("%s", tmpAsk.data.title, 10); setbuf(stdin, NULL);

			while (tmp != 0) {
				if (strcmp(tmp->data.title, tmpAsk.data.title) == 0) { //���������� � ������ ���������
					rpt = false; //������ �� ���� ���� ���� ���������� �������
					printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
				}
				tmp = tmp->next;
			}
			if (rpt) printf("������ ������������ � ������ ���.\n\n"); //���� ���������� ���
			break;

		case 2:
			printf("������������� > "); scanf_s("%s", tmpAsk.data.producer, 10); setbuf(stdin, NULL);

			while (tmp != NULL) {
				if (strcmp(tmp->data.producer, tmpAsk.data.producer) == 0) { //���������� � ������ ��������������
					rpt = false; //������ �� ���� ���� ���� ���������� �������
					printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
				}
				tmp = tmp->next;
			}
			if (rpt) printf("������ ������������� � ������ ���.\n\n"); //���� ���������� ���
			break;

		case 3:
			printf("���-�� >");	scanf_s("%d", &tmpAsk.data.count); setbuf(stdin, NULL);

			while (tmp != NULL) {
				if (tmp->data.count == tmpAsk.data.count) {
					rpt = false;
					printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
				}
				tmp = tmp->next;
			}
			if (rpt) printf("������ ���������� � ������ ���.\n\n");
			break;

		case 4:
			printf("���� > "); scanf_s("%lf", &tmpAsk.data.price); setbuf(stdin, NULL);

			while (tmp != NULL) {
				if (tmp->data.price == tmpAsk.data.price) {
					rpt = false;
					printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
				}
				tmp = tmp->next;
			}
			if (rpt) printf("����� ���� � ������ ���.\n\n");
			break;

		case 5: return 0;

		default: printf("Wrong number!\n");
			break;
		}
	}
}

int searchByParamFromTail(Tlist* tail, int count) {
	int point;
	Tlist* tmp;
	Tlist tmpAsk;

	while (true) {
		bool rpt = true;
		tmp = tail;
		printf("\n������ ��...\n");
		printf("1. ������������ \n");
		printf("2. ������������� \n");
		printf("3. ���-�� ������ \n");
		printf("4. ���� \n");
		printf("5. �����\n");
		printf(">> "); scanf_s("%d", &point);

		switch (point) {
		case 1:
			printf("������������ > "); scanf_s("%s", tmpAsk.data.title, 10); setbuf(stdin, NULL);

			while (tmp != NULL) {
				if (strcmp(tmp->data.title, tmpAsk.data.title) == 0) { //���������� � ������ ���������
					rpt = false; //������ �� ���� ���� ���� ���������� �������
					printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
				}
				tmp = tmp->prev;
			}
			if (rpt) printf("������ ������������ � ������ ���.\n\n"); //���� ���������� ���
			break;

		case 2:
			printf("������������� > "); scanf_s("%s", tmpAsk.data.producer, 10); setbuf(stdin, NULL);

			while (tmp != NULL) {
				if (strcmp(tmp->data.producer, tmpAsk.data.producer) == 0) { //���������� � ������ ��������������
					rpt = false; //������ �� ���� ���� ���� ���������� �������
					printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
				}
				tmp = tmp->prev;
			}
			if (rpt) printf("������ ������������� � ������ ���.\n\n"); //���� ���������� ���
			break;

		case 3:
			printf("���-�� >");	scanf_s("%d", &tmpAsk.data.count); setbuf(stdin, NULL);

			while (tmp != NULL) {
				if (tmp->data.count == tmpAsk.data.count) {
					rpt = false;
					printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
				}
				tmp = tmp->prev;
			}
			if (rpt) printf("������ ���������� � ������ ���.\n\n");
			break;

		case 4:
			printf("���� > "); scanf_s("%lf", &tmpAsk.data.price); setbuf(stdin, NULL);

			while (tmp != NULL) {
				if (tmp->data.price == tmpAsk.data.price) {
					rpt = false;
					printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
				}
				tmp = tmp->prev;
			}
			if (rpt) printf("����� ���� � ������ ���.\n\n");
			break;

		case 5: return 0;

		default: printf("Wrong number!\n");
			break;
		}
	}
	
}

void addToList(Tlist*& head, int& count, int poz) {
	Tlist* tmp = new Tlist;
	if (poz == 1) {
		tmp->prev = NULL;
		tmp->next = head;
		head->prev = tmp;
		head = tmp;
	}
	else {
		Tlist* tmpPoz = head;
		for (int i = 0; i < poz - 2; i++)
			tmpPoz = tmpPoz->next;

		tmp->next = tmpPoz->next;
		if (tmp->next != NULL) {
			tmp->next->prev = tmp;
		}
		tmp->prev = tmpPoz;
		tmpPoz->next = tmp;
	}

	printf("\n������� >> \n");
	printf("������������:  "); scanf_s("%s", tmp->data.title, 20);      setbuf(stdin, NULL);
	printf("�������������: "); scanf_s("%s", tmp->data.producer, 20);	setbuf(stdin, NULL);
	printf("���������� �.: "); scanf_s("%d", &tmp->data.count);
	printf("����:          "); scanf_s("%lf", &tmp->data.price);
	count++;
}

void deleteFromList(Tlist*& head, int& count, int poz) {
	if (head != NULL) {
		Tlist* tmp = head, * tmpPoz = NULL;

		if (poz == 1) {//���� ������� ������
			tmpPoz = head->next; //���������� ��������� ������ �� ����. �������
			tmpPoz->prev = NULL;
			delete head;
		}
		else { //������������ � �������� ������������ �� ������(��������)
			for (int i = 0; i < poz - 1; i++) {
				tmpPoz = tmp;
				tmp = tmp->next;
			}

			tmpPoz->next = tmp->next;
			if (tmpPoz->next != NULL) 
				tmpPoz->next->prev = tmpPoz;
			delete tmp;
		}
		count--;
	}
	else printf("\n������ �������� ������.\n");
	
}

void listSorting(Tlist* head, int count) {
	if (head != NULL) {
		Tlist* temp = head;
		Tlist* hPtr, * trash, * tmp;
		tmp = new Tlist;

		for (int i = 0; i < count; i++) {
			hPtr = head;                 //����������� ������ ������
			while (hPtr->next != NULL) { //���� ������ �� ���������
				temp = hPtr->next;        //����������� �������� ������� ������ �����. 
				if (strcmp(hPtr->data.title, temp->data.title) > 0) { //���������� ������ � ������� ������
					trash = temp->next;   //���������� ��������� �� ����� �������
					*tmp = *hPtr;         //��������� ��������� �� ������� �������
					*hPtr = *temp;        //����������� ���������(2) ������� �� ������ ������
					delete temp;
					hPtr->next = new Tlist; //� ������ ������� �������� ����������� ������
					*hPtr->next = *tmp;     //������ ������� ������ ��������� �� ����������
					hPtr->next->next = trash;
				}
				hPtr = hPtr->next;
			}
		}
		delete tmp;
	}
	else printf("\n������ �������� ������.\n");
}

void createFile(Tlist* head, int count) {
	if (head != NULL) {
		Tlist* tmp = head;
		FILE* file = 0;

		if ((file = fopen("fileForList.txt", "w")) == NULL) { //��������� ���� � ��������� ���������� �� ��
			printf("���� ��� ������ �� ������");
			exit(1);
		}

		for (int i = 0; i != count; i++) {
			fprintf_s(file, "%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
			tmp = tmp->next;
		}
		fclose(file);
	}
	else printf("\n������ �������� ������.\n");
}

void oldListKill(Tlist*& head) {
	Tlist* tmp = head;
	while (tmp) {
		head = head->next;
		delete tmp;
		tmp = head;
	}
}

void createListFromFile(Tlist*& head, Tlist*& tail) {
	FILE* file = NULL;
	if ((file = fopen("fileForList.txt", "r")) == NULL) { //��������� ���� � ��������� ���������� �� ��
		printf("���� ��� ������ �� ������");
		exit(1);
	}

	int count = 0;
	while (fscanf(file, "%*[^\n]%*c") != EOF)
		count++;
	if (ferror(file))
		printf("������ �� ����� �������� �����\n");

	Tlist* tmp = new Tlist;
	head = tail = tmp;

	/*head = new Tlist;
	Tlist* tmpPoz, * tmp;
	tmpPoz = tmp = head;*/

	fseek(file, 0, SEEK_SET); //����� ������ ������, ��� ��� ������� �� �������� =)
	for (int i = 0; i != count; i++) {
		fscanf_s(file, "%s", tmp->data.title, 20);
		fscanf_s(file, "%s", tmp->data.producer, 20);
		fscanf_s(file, "%d", &tmp->data.count);
		fscanf_s(file, "%lf", &tmp->data.price);
		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;
		tmp = new Tlist;
		tmp->next = NULL;
	}
	Tlist* end = tail;
	for (int i = 0; i != count; i++) { end = end->prev; }
	end->prev = NULL;
	fclose(file);
}