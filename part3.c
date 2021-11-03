/* Assignment3: Author- Daniel Grounin*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 100

void Ch2Val(char str[]);
void Decipher(char str2[LEN]);

int main(void) {
	printf("Q5\n"); //Question5 - func calculate elements in a string
	char str[] = "12.332 + 14.33 =";
	Ch2Val(str);

	printf("Q6\n"); //Question6 - function checks the encrypted sentence 
	char string2[LEN] = "Btwlzx Dqqes Eq|pj4 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt5";
	printf("Your encrypted token reveals as: ");
	Decipher(string2);
}

void Ch2Val(char str[]) {
	int flag = 0, flag2 = 0;
	int posOfdot = 0, posOfdot2 = 0, space = 0, Index = 0;
	int length1 = 0, length2 = 0;
	int opLen1 = 0, opLen2 = 0;
	float op1 = 0, op2 = 0, op3 = 0, op4 = 0;
	int temp2 = 0;
	int k = 0;
	while (str[k] != ' '){ //run until space found
		k++; 
		if (str[k] == '.') { //if we got dot flag as yes
			flag = 1;
			posOfdot = k; //position of dot
		}
		opLen1 = k; //the length of the number before the decimal point
	}
	if (flag == 1){ //if we will find decimal point
		for (int i = 0; i < posOfdot; i++) { //connect the number before decimal point
			op1 = op1 * 10.0 + (str[i] - '0');
		}
		for (int j = posOfdot + 1; j < opLen1 + 1; j++) { 
			length1++;
			op2 = op2 * 10.0 + (str[j] - '0');
		}
		int temp = op2; //connect the number after tyhe decimal point
		while (temp > 0) {
			op2 /= 10;
			temp /= 10;
		}
		op1 = (float)(op1 + op2);  //full number saved
	}
	else {
		for (int l = 0; str[l] != ' '; l++) {
			op1 = op1 * 10.0 + (str[l] - '0');
		}
	}
	//part of operand2
	int c = 0;
	while (str[c] != '=') { //run untill not '='
		c++;
		if (str[c] == ' ') { //check for spaces
			space++;
		}
		if (space == 2 && str[c] == ' ') { //we need to add one after space to get to the start of the second operand
			Index = c + 1;
		}
	}
	int j = Index;
	while (str[k] != ' ') {
		if (str[k] == '.') {
			flag2 = 1;
			posOfdot2 = k;
		}
		opLen2 = k;  //the length of the number before the decimal point
	}
	int m = Index;
	while (str[m] != ' ') {
		m++;
		if (str[m] == '.') {
			flag2 = 1;
			posOfdot2 = m; 
		}
		opLen2 = m; 
	}
	if (flag2 == 1){ // connect the number before decimal point
		for (int k = Index; k < posOfdot2; k++) {
			op3 = op3 * 10.0 + (str[k] - '0');
		}
		for (int j = posOfdot2 + 1; j < opLen2 + 1; j++) {
			length2++;
			op4 = op4 * 10.0 + (str[j] - '0');
		}
		int temp2 = op4;
		while (temp2 > 0) { //connect the number after tyhe decimal point
			op4 /= 10;
			temp2 /= 10;
		}
		op3 = (float)(op3 + op4); //full number saved
	}
	else {
		for (int l = Index; str[l] != ' '; l++) {
			op3 = op3 * 10.0 + (str[l] - '0');
		}
	}
	//part of operand
	float Result = 0;
	int i = 0;
	while (str[i] != ' '){ //check where the operand index
		i++;
	}
	i++;
	if (str[i] == '+') {
		Result = op1 + op3;
	}
	if (str[i] == '-') {
		Result = op1 - op3;
	}
	if (str[i] == '*') {
		Result = op1 * op3;
	}
	if (str[i] == '/') {
		Result = op1 / op3;
	}
	if (flag2 == 1 && flag == 1) { //"truth table" checks the parts after the decimal point
		if (opLen1 - posOfdot >= opLen2 - posOfdot2) { //remove the full part from the decimal part to check only the remainder 
			printf("the result is %.*f\n", opLen2 - posOfdot2, Result);
		}
		else {
			printf("the result is %.*f\n", opLen1 - posOfdot, Result);
		}
	}
	if (flag == 0 && flag2 == 1) {
		printf("the result is %.*f\n", opLen2 - posOfdot2, Result);
	}
	if (flag == 1 && flag2 == 0) {
		printf("the result is %.*f\n", opLen1 - posOfdot, Result);
	}
	if (flag == 0 && flag2 == 0) {
		printf("the result is %.0f\n", Result);
	}
	return 0;
}

void Decipher(char str2[LEN]){ //encrypted token sequence function
	int i, j = 1;
	//the main idea of the encryption is to convert the characters by the index of the placed char 
	// as long the letter is further we count how further it is and convert the value to every char by the gapping from the start ,exmp: char1 => +1 ,char5 =>+5 in ascii
	for (i = 0; str2[i] != '\0'; i++, j++){ //run until last place in the string 
		if (str2[i] != ' ') {
			str2[i] = str2[i] - j;
		}
		else{
			str2[i] = str2[i];
			j *= 0;
		}
	}
	puts(str2);
}
