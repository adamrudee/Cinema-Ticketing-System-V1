#include<iostream>
#include<iomanip>

using namespace std;

//function prototype
void welcomeMenu();//
void movieTimeS();//
void movieTimeG();//
void movieTimeJ();//
void tPrice();
void Combo();
void alaCarte();
void seatMenu();//
void merchmenu();//
void minMaxTicket(int X, int Y, int Z);
void paymentMenu();//
int functionTotal(int a, int b, int c, int d, int e);
double avg(double &i, int u);

int main(){
	
	//Declaration variable
	char movieAnswer = ' ', student = ' ',  moreTicket = ' ', moreFood = ' ', merchandiseAnswer = ' ', membershipAnswer = ' ', addMerch =' ', paymentMethod = ' ', joinMembership = ' ';
	string food_name = " ", food_name2 = " ", name = " ", phone_num = " ", combo = " ", aCarte = " ", merchandise = " ", paymentName = " ";
	string movie_name = " ", date = " ", showTime = " ", hall = " ", hallCode = " ", studentID = " ", membershipID = " ", membership = " ", membershipCharge = " ";
	int timeAns = 0, numStudent = 0, cTicket = 0, aTicket = 0, totalWatch = 0, totticketS = 0, totticketG = 0, totticketJ = 0, prefer = 0, quantity = 0, mQty = 0, user = 0;
	double priceStudent = 0.0, memberPrice = 0.0, membershipDiscount = 0.0, totalMemberPrice = 0.0, discountMember = 0.0;
	double afterTax = 0.0, priceDiscount = 0.0, merchPrice = 0.0, totalMerchPrice = 0.0, member = 0.0, discount = 0.0, income = 0.0;
	double childPrice = 0.0, adultPrice = 0.0, studentPrice = 0, total = 0.0, comboPrice = 0.0, alaPrice = 0.0, totalPriceFood = 0.0, totalPriceFood1 = 0.0, totalPriceFood2 = 0.0, methodDiscount = 0.0, memPrice = 0.0;
	const double tax = 0.06;
	
	//do-while loop statement
	do{
		//customer information
		cout<<"\n---------------------------INSERT CUSTOMER INFORMATION-----------------------------"<<endl;
		cout<<"\nPlease enter your name\t : ";
		cin>>ws;
		getline(cin, name);
		cout<<"\nPlease enter your phone number : ";
		cin>>phone_num;
		cout<<"\nTHANK YOU FOR YOUR COMMITMENT.\n"<<endl;
	
		//call function for table for selection movie
		welcomeMenu();//
		cout<<"Pick a date to watch this movie? [xx/xx/xxxx] : ";
		cin>>date;
		
		//Selection multiple switch case and if-else_if statement
		cout<<"\nPlease select the movie you want [S | G | J] : ";
		cin>>movieAnswer;
		
		//reset initialize for the second user
		priceStudent = 0.0, childPrice = 0.0, adultPrice = 0.0;
		numStudent = 0, cTicket = 0, aTicket = 0;
	
		if(movieAnswer == 'S' || movieAnswer == 'G' || movieAnswer == 'J'){
			switch(movieAnswer){
				case 'S' :
					movie_name = "Spider-Man: Across the Spider-Verse";
					
					//function call that display movie time
					movieTimeS();
					
					cout<<"Please Select the Showtime : ";
					cin>>timeAns;
					
					//IF-ELSE IF Selection movie time	
					if(timeAns == 1){
						showTime = "10:30 am";
					}
					else if(timeAns == 2){
						showTime = "3:15 pm";
					}
					else if(timeAns == 3){
						showTime = "9:00 pm";
					}
					else{
						cout<<"\nERROR! PLEASE SELECT THE VALID MOVIE TIME CODE.";
					}
					
					//call function that display menu type of hall and ticket price
					tPrice();
				
					cout<<"\nEnter hall code : ";
					cin>>hallCode;
					
					cout<<"\n------------------QUANTITIY OF PERSON WHO WANT TO WATCH THE MOVIE------------------"<<endl;
					cout<<"\n Is there a student among you? [Y/N] ";
					cout<<"-It's not valid if you choose FS hall- : ";
					cin>>student;
					
					if (hallCode=="IM"){
						studentPrice = 20.00;
					} 
					else if (hallCode=="AT"){
						studentPrice = 17.00;
					}

					//looping while statement to ask is there another student
					while(student == 'Y' || student == 'y'){
						
					cout<<" Please enter your student ID number : ";
					cin>>studentID;
					numStudent++;
					priceStudent += studentPrice;
					
					cout<<"\n Is there another student among you? [Y|N] : ";
					cin>>student;
					}
					
					//Selection if statement to insert child and adult ticket
					if(student == 'N' || student == 'n'){
						cout<<"\n Please enter number of child : ";
						cin>>cTicket;
						cout<<" Please enter number of adult : ";
						cin>>aTicket;
					}
					
					if (hallCode=="IM"){
						childPrice += cTicket*15.00;
						adultPrice += aTicket*30.00;
						hall = "IMAX";
					} 
					else if (hallCode=="AT"){
						childPrice += cTicket*12.00;
						adultPrice += aTicket*27.00;
						hall = "ATMOS";
					} 
					else if (hallCode=="FS"){
						childPrice += cTicket*20.00;
						adultPrice += aTicket*30.00;
						hall = "FAMILY SESSION";
					}
					
					//calculate total person that purchased the ticket and the total price of the ticket
					totalWatch = numStudent + cTicket + aTicket;
					totticketS = childPrice + adultPrice + priceStudent;
					
					//output calculation total person that purchased the ticket and the total price of the ticket
					cout<<"\nTotal student ticket (RM) : "<<priceStudent<<endl;
					cout<<"Total child ticket   (RM) : "<<childPrice<<endl;
					cout<<"Total adult ticket   (RM) : "<<adultPrice<<endl;
					cout<<"Total tickets\t     (RM) : "<<totticketS<<endl;
					
					break;
					
				case 'G' :
					movie_name = "Godzilla x Kong: The New Empire";
					
					//function call that display movie time
					movieTimeG();
					
					cout<<"Please Select the Showtime : ";
					cin>>timeAns;
					
					if(timeAns == 1){
						showTime = "11:00 am";
						}
					else if(timeAns == 2){
						showTime = "4:30 pm";
					}
					else if(timeAns == 3){
						showTime = "8:00 pm";
					}
					else{
						cout<<"\nERROR! PLEASE SELECT THE VALID MOVIE TIME CODE.";
					}
					
					//call function that display menu type of hall and ticket price
					tPrice();
				
					cout<<"\nEnter hall code : ";
					cin>>hallCode;
					
					cout<<"\n------------------QUANTITIY OF PERSON WHO WANT TO WATCH THE MOVIE------------------"<<endl;
					cout<<"\n Is there a student among you? [Y/N] ";
					cout<<"-It's not valid if you choose FS hall- : ";
					cin>>student;
					
					if (hallCode=="IM"){
						studentPrice = 20.00;
					} 
					else if (hallCode=="AT"){

						studentPrice = 17.00;
					} 
					
					//looping while statement
					while(student == 'Y' || student == 'y'){
						
					cout<<" Please enter your student ID number : ";
					cin>>studentID;
					numStudent++;
					priceStudent += studentPrice;
					
					cout<<"\n Is there another student among you? [Y|N] : ";
					cin>>student;
					}
					
					//Selection if statement to insert child and adult ticket
					if(student == 'N' || student == 'n'){
						cout<<"\n Please enter number of child : ";
						cin>>cTicket;
						cout<<" Please enter number of adult : ";
						cin>>aTicket;
					}
					
									
					if (hallCode=="IM"){
						childPrice += cTicket*15.00;
						adultPrice += aTicket*30.00;
						hall = "IMAX";
					} 
					else if (hallCode=="AT"){
						childPrice += cTicket*12.00;
						adultPrice += aTicket*27.00;
						hall = "ATMOS";
					} 
					else if (hallCode=="FS"){
						childPrice += cTicket*20.00;
						adultPrice += aTicket*30.00;
						hall = "FAMILY SESSION";
					}
					
					//calculate total person that purchased the ticket and the total price of the ticket
					totalWatch = numStudent + cTicket + aTicket;
					totticketG = childPrice + adultPrice + priceStudent;
					
					//output calculation total person that purchased the ticket and the total price of the ticket
					cout<<"\nTotal student ticket (RM) : "<<priceStudent<<endl;
					cout<<"Total child ticket   (RM) : "<<childPrice<<endl;
					cout<<"Total adult ticket   (RM) : "<<adultPrice<<endl;
					cout<<"Total tickets\t     (RM) : "<<totticketG<<endl;
					
					
					break;
					
				case 'J' :
					movie_name = "John Wick: Chapter 4";
					
					//function call that display movie time
					movieTimeJ();
					
					cout<<"Please Select the Showtime : ";
					cin>>timeAns;
						
					if(timeAns == 1){
						showTime = "12:00 am";
					}
					else if(timeAns == 2){
						showTime = "6:40 pm";
					}
					else if(timeAns == 3){
						showTime = "9:00 pm";
					}
					else{
						cout<<"ERROR! PLEASE SELECT THE VALID MOVIE TIME CODE.";
					}
					
					//call function that display menu type of hall and ticket price
					tPrice();
				
					cout<<"\nEnter hall code : ";
					cin>>hallCode;
					
					cout<<"\n------------------QUANTITIY OF PERSON WHO WANT TO WATCH THE MOVIE------------------"<<endl;
					cout<<"\n Is there a student among you? [Y/N] ";
					cout<<"-It's not valid if you choose FS hall- : ";
					cin>>student;
					
					if (hallCode=="IM"){
						studentPrice = 20.00;
					} 
					else if (hallCode=="AT"){

						studentPrice = 17.00;
					} 
					
					//looping while statement
					while(student == 'Y' || student == 'y'){
						
					cout<<" Please enter your student ID number : ";
					cin>>studentID;
					numStudent++;
					priceStudent += studentPrice;
					
					cout<<"\n Is there another student among you? [Y|N] : ";
					cin>>student;
					}
					//Selection if statement to insert child and adult ticket
					if(student == 'N' || student == 'n'){
						cout<<"\n Please enter number of child : ";
						cin>>cTicket;
						cout<<" Please enter number of adult : ";
						cin>>aTicket;
					}
					
				
					if (hallCode=="IM"){
						childPrice += cTicket*15.00;
						adultPrice += aTicket*30.00;
						hall = "IMAX";
					} 
					else if (hallCode=="AT"){
						childPrice += cTicket*12.00;
						adultPrice += aTicket*27.00;
						hall = "ATMOS";
					} 
					else if (hallCode=="FS"){
						childPrice += cTicket*20.00;
						adultPrice += aTicket*30.00;
						hall = "FAMILY SESSION";
					}
					
					//calculate total person that purchased the ticket and the total price of the ticket
					totalWatch = cTicket + aTicket,numStudent;
					totticketJ = childPrice + adultPrice + priceStudent;
					
					//output calculation total person that purchased the ticket and the total price of the ticket
					cout<<"\nTotal student ticket (RM) : "<<priceStudent<<endl;
					cout<<"Total child ticket   (RM) : "<<childPrice<<endl;
					cout<<"Total adult ticket   (RM) : "<<adultPrice<<endl;
					cout<<"Total tickets\t     (RM) : "<<totticketJ<<endl;
					
					break;
					
				default :
					cout<<"\nERROR! PLEASE SELECT THE VALID MOVIE CODE.";
				}
		}
		else{
			cout<<"\nERROR! PLEASE SELECT THE VALID MOVIE CODE.";
		}
		
		//seat of cinema
		seatMenu();
	
		//array seat of cinema
		int seat [156] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
		25, 26, 27, 28, 29, 30, 31, 32, 33, 34,35, 36,
		37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
		49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
		61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72,
		73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84,
		85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96,
		97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108,
		109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
		121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132,
		133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144,
		145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156};
	
		
		//looping statement for user to enter the seat of total person
		for(int i = 1; i<=totalWatch; i++){
			cout<<"\nPlease choose your no. " <<i<< " seat: ";
			cin>>seat[i];
		}
		
		//looping while statement for food
		cout<<"\nDo you want to add on food? [Y|N] : ";
		cin>>moreFood;
		
		//reset initialize for the second user
		totalPriceFood1 = 0.0, totalPriceFood2 = 0.0;
		
		while(moreFood == 'Y'){
			
			cout<<"\nDo you prefer combo or ala carte? < 1 - Combo | 2 - Ala Carte > : ";
			cin>>prefer;
		
			if(prefer == 1){
				
				//function call combo menu
				Combo();
			
				cout<<"Please select add-on combo code : ";
			
				cin>>combo;
			
				if(combo == "FC01"){
					food_name = "Popcorn + Coke";
					cout<<"Please enter the quantity of food combo : ";
					cin>>quantity;
					comboPrice = 18.00;		
				}
				else if(combo == "FC02"){
					food_name = "Caramel Popcorn + Coke";
					cout<<"Please enter the quantity of food combo : ";
					cin>>quantity;
					comboPrice = 21.00;
				}
				else if(combo == "FC03"){
					food_name = "Chips + Coke ";
					cout<<"Please enter the quantity of food combo : ";
					cin>>quantity;
					comboPrice = 17.00;
				}
				else if(combo == "FC04"){
					food_name = "Chicken Sausage + Coke";
					cout<<"Please enter the quantity of food combo : ";
					cin>>quantity;
					comboPrice = 15.00;
				}
				else if(combo == "FC05"){
					food_name = "Chicken Nuggets + Coke";
					cout<<"Please enter the quantity of food combo : ";
					cin>>quantity;
					comboPrice = 14.00;	
				}
				
				//calculation for combo
				totalPriceFood1 += comboPrice*quantity;
				
				//output from calcualtion combo
				cout<<"\nTotal food price [combo] = RM "<<totalPriceFood1<<endl;
			
				cout<<"\nDo you want to add-on more food? [Y|N] : ";
				cin>>moreFood;
			
			}
			else if(prefer == 2){
			
				//function call for ala carte menu
				alaCarte();
			
				cout<<"Please select add-on ala carte code : ";
				cin>>aCarte;
			
				if(aCarte == "F01"){
					food_name2 = "Popcorn";
					cout<<"Please enter the quantity of food : ";
					cin>>quantity;
					alaPrice = 14.00;
				}
				else if(aCarte == "F02"){
					food_name2 = "Caramel Popcorn";
					cout<<"Please enter the quantity of food : ";
					cin>>quantity;
					alaPrice = 17.00;
				}
				else if(aCarte == "F03"){
					food_name2 = "Chips";
					cout<<"Please enter the quantity of food : ";
					cin>>quantity;
					alaPrice = 9.00;
				}
				else if(aCarte == "F04"){
					food_name2 = "Chicken Sausage";
					cout<<"Please enter the quantity of food : ";
					cin>>quantity;
					alaPrice = 11.00;
				}
				else if(aCarte == "F05"){
					food_name2 = "Chicken Nuggets";
					cout<<"Please enter the quantity of food : ";
					cin>>quantity;
					alaPrice = 10.00;
				}
				
				//calculation for ala carte
				totalPriceFood2 += alaPrice*quantity;
			
				//output from calcualtion ala carte
				cout<<"\nTotal food price [ala carte] = RM "<<totalPriceFood2<<endl;
			
				cout<<"\nDo you want to add more food? [Y|N] : ";
				cin>>moreFood;
			}
		
		}
		
		//reset initialize for the second user
		totalPriceFood = 0.0;
		
		//calculation for combo + ala carte
		totalPriceFood = totalPriceFood1 + totalPriceFood2;
		
		//output from calculation combo + ala carte
		cout<<"\nTotal food price [combo + ala carte] = RM "<<totalPriceFood<<endl;
		
		//looping while statement for merchandise
		cout<< "\nDo You Want to Grab Some Merchandise Before Head Home? <Y|N>? : ";
		cin>>merchandiseAnswer;
		
		//reset initialize for the second user
		totalMerchPrice = 0.0;
		
		while(merchandiseAnswer=='Y'){
			
			//function call for merchandise menu
			merchmenu();
			
			cout<< "Please select the merchandise that you want : ";
			cin>>addMerch;
		
			switch (addMerch){
        		case 'A': 
					merchandise = "Spider-man toy";
					cout<<"Please enter the quantity of the merch      : ";
					cin>>mQty;
        			merchPrice =  50.00*mQty;
					break;	
        		case 'B':  
					merchandise = "Godzilla & Kong pillow";
					cout<<"Please enter the quantity of the merch      : ";
					cin>>mQty;
					merchPrice = 100.00*mQty;           
        			break;
        		case 'C': 
					merchandise = "John Wick wig ";
					cout<<"Please enter the quantity of the merch      : ";
					cin>>mQty;
					merchPrice =  30.00*mQty;           
					break;	
				default : 
					cout<<"Invalid option! Please try again."<<endl;
				}
		
			cout<<"Merchandise Price\t\t\t    : RM "<<merchPrice<<endl;
		
			cout<< "\nDo you want to add more merchandise? <Y|N>  : ";
			cin>>merchandiseAnswer;
			
			//calculation for total merchandise that have been purchased
			totalMerchPrice += merchPrice;
		}
		if(merchandiseAnswer == 'N'){
			merchPrice = 0.0;
			totalMerchPrice += merchPrice;
		}
		
		//output for type of merchandise and the total merchandise that have been purchased
		cout<<"\nMerchandise Type \t  : "<<merchandise<<endl;
		cout<<"Total price [merchandise] : RM "<<totalMerchPrice<<endl;
		
		//function call that calculatate item that user purchase
		total = functionTotal(childPrice, adultPrice, priceStudent, totalPriceFood, totalMerchPrice);//////
		
		//selection if_else-if statement whether join membership 
		cout<<"\nDo you join our membership? <Y|N> : ";
		cin>>joinMembership;
	
		if(joinMembership == 'Y'){
			cout<<"Please enter your membership ID   : ";
			cin>>membershipID;
			memberPrice = 0.0;
			membershipDiscount =  0.3;
			membership = "YES";
			membershipCharge = "NO";
		
			//calculate user discount who joined membership
			totalMemberPrice = total + memberPrice;
			member = totalMemberPrice * membershipDiscount;
			discountMember = totalMemberPrice - (member);
			
			//output from calcualtion discount for membership
			cout<<"total price [membership] : RM"<<discountMember<<endl;
			cout<<"membership\t\t : "<<membership<<endl;
		}
		else if (joinMembership == 'N'){	
			cout<<"\n---Do you want to join our membership with---"<<endl;
			cout<<"----------------------------------------------"<<endl;
			cout<<"PRICE   : RM 15"<<endl;
			cout<<"BENEFIT : 30% OFF FOR YOUR PURCHASING"<<endl;
			cout<<"----------------------------------------------"<<endl;
			cout<<"\n<Y|N>   : ";
			cin>>membershipAnswer;
			  
    		if(membershipAnswer == 'N' || membershipAnswer == 'n'){
    			membership = "NO";
    			membershipCharge = "NO";
    			memberPrice = 0.0;
				membershipDiscount = 0.0;        
			}
			else if(membershipAnswer == 'Y' || membershipAnswer != 'Y'){
    			membership = "YES";
    			membershipCharge = "YES";
    			memberPrice = 15.00;
				membershipDiscount =  0.3;
			}
			
			//calculate user discount whether he/she want to join membership or don't want
			totalMemberPrice = total + memberPrice;
			member = totalMemberPrice * membershipDiscount;
			discountMember = totalMemberPrice - (member);
	
			//output from calcualtion discount for membership
			cout<<"total price [membership] : RM"<<discountMember<<endl;
			cout<<"membership\t\t : "<<membership<<endl;
		}
		
		//function call for payment method menu
		paymentMenu();
		
		cout<<"Please enter payment code : ";
		cin >> paymentMethod;
		
		//Switch case statement for payment method
    	switch (paymentMethod) {
        	case 'D':
          		methodDiscount = 0.03;
          	  	paymentName = "Debit/Credit Card";
         		break;
        	case 'T':
        	    methodDiscount = 0.05;
        	    paymentName = "Touch & Go eWallet";
        	    break;
        	case 'C':
        		methodDiscount = 0.0;
        		paymentName = "Cash";
            	break;
    		default:  
				cout << "INVALID PAYMENT CODE! PLEASE TRY AGAIN." << endl;
		}
		

		//calculate payment method discount and tax that user have to pay
		discount = discountMember * methodDiscount;
		priceDiscount = discountMember - (discount);
		afterTax = priceDiscount + (priceDiscount * tax);
		

		
		//customer receipt
		cout<<"\n-----------------------------------------------------------------------------------"<<endl;
		cout<<"-----------------------------CINEMA TICKETING SYSTEM-------------------------------"<<endl;
		cout<<"-----------------------------------------------------------------------------------"<<endl;
		cout<<"\n | \t\tNAME\t\t\t\t : "<<name<<endl;
		cout<<"\n | \t\tPHONE NUMBER\t\t\t : "<<phone_num<<endl;
		cout<<"\n | \t\tMOVIE NAME\t\t\t : "<<movie_name<<endl;
		cout<<"\n | \t\tMOVIE TIME\t\t\t : "<<showTime<<endl;
		cout<<"\n | \t\tMOVIE HALL\t\t\t : "<<hall<<endl;
		cout<<"\n | \t\tDATE\t\t\t\t : "<<date<<endl;
		
		//looping statement to display the seat of total person 
		for(int i = 1; i<=totalWatch; i++){
			cout<<"\n | \t\tSEAT NUMBER FOR PERSON "<<i<<" is\t : "<<seat[i]<<" "<<endl;
		}
		
		cout<<"\n | \t\tFOOD AND BEVERAGE\t\t : "<<food_name<<endl;
		cout<<"\n | \t\tFOOD ONLY\t\t\t : "<<food_name2<<endl;
		cout<<fixed<<setprecision(2);
		cout<<"\n | \t\tTOTAL STUDENT PRICE\t\t : RM"<<priceStudent<<endl;
		cout<<"\n | \t\tTOTAL CHILD PRICE\t\t : RM"<<childPrice<<endl;
		cout<<"\n | \t\tTOTAL ADULT PRICE\t\t : RM"<<adultPrice<<endl;
		
		//function call to find maximum or mininmum ticket from student, child, adult ticket
		minMaxTicket(numStudent, cTicket, aTicket);
		cout<<"\n | \t\tTOTAL FOOD COMBO+ALA CARTE PRICE : RM"<<totalPriceFood<<endl;
		cout<<"\n | \t\tTOTAL MERCHANDISE PRICE\t\t : RM"<<totalMerchPrice<<endl;
		cout<<"\n | \t\tTOTAL PURCHASING\t\t : RM"<<total<<endl;
		cout<<"\n | \t\tMEMBERSHIP\t\t\t : "<<membership<<endl;
		cout<<"\n | \t\tMEMBERSHIP CHARGE [RM 15]\t : "<<membershipCharge<<endl;
		cout<<"\n | \t\tTOTAL PURCHASING + CHARGE\t : RM"<<totalMemberPrice<<endl;
		cout<<"\n | \t\tMEMBERSHIP DISCOUNT\t\t : RM"<<member<<endl;
		cout<<"\n | \t\tPRICE AFTER MEMBERSHIP DISCOUNT  : RM"<<discountMember<<endl;
		cout<<"\n | \t\tPAYMENT METHOD\t\t\t : "<<paymentName<<endl;
		cout<<"\n | \t\tPAYMENT METHOD DISCOUNT\t\t : RM"<<discount<<endl;
		cout<<"\n | \t\tTOTAL PRICE\t\t\t : RM"<<priceDiscount<<endl;
		cout<<"\n | \t\tTOTAL PRICE AFTER TAX (6%)\t : RM"<<afterTax<<endl;
		cout<<"---------------------------------------------------------------------------------"<<endl;
		
		cout<<"\nDo you want to purchase another tickets? [Y|N]? : ";
		cin>>moreTicket;
		
		cout<<endl;
		
		//calculate how many user use our system and + the income from user purchased
		user++;
		income = income + afterTax;
		
		
	}while(moreTicket == 'Y');
	
	//total output that every user purchased and display the average
	cout<<"\nTotal purchased tickets   : "<<user<<endl;
	cout<<"Total income\t\t  : RM"<<income<<endl;
	avg(income, user);
	cout<<"\nThank you for using our service! See you next time!"<<endl;
	
	return 0;
}
//function definition
void welcomeMenu(){
	
	cout<<"-------------------------WELCOME TO CINEMA TICKETING SYSTEM------------------------"<<endl;
	cout<<"---------------------------------SELECT A MOVIE!-----------------------------------"<<endl;
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	cout<<"Code\t\t\tMovie\t\t\t\t\tGenre"<<endl;
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	cout<<" S\tSpider-Man: Across the Spider-Verse\t\t=> Action and Comedy  "<<endl;
	cout<<" G\t  Godzilla x Kong: The New Empire \t\t=> Action and Sci-Fi  "<<endl;
	cout<<" J\t\tJohn Wick: Chapter 4               \t=> Action and Thriller"<<endl;
	cout<<"-----------------------------------------------------------------------------------\n"<<endl;
	
}
void movieTimeS(){
	
	cout<<"\nMOVIE TIME"<<endl;
	cout<<"1 - 10:30 am"<<endl;
	cout<<"2 - 3:15 pm"<<endl;
	cout<<"3 - 9:00 pm"<<endl;
	
}
void movieTimeG(){
	
	cout<<"\nMOVIE TIME"<<endl;
	cout<<"1 - 11:00 am"<<endl;
	cout<<"2 - 4:30 pm"<<endl;
	cout<<"3 - 8:00 pm"<<endl;
	
}
void movieTimeJ(){
	
	cout<<"\nMOVIE TIME"<<endl;
	cout<<"1 - 12:00 am"<<endl;
	cout<<"2 - 6:40 pm"<<endl;
	cout<<"3 - 9:00 pm"<<endl;
					
}
void tPrice(){

	cout<< "\n\t\t\t\tSELECT HALL!"<<endl;
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	cout<<"Hall Code \t\t\tCategory \t\t\tPrice(RM)" << endl;
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	cout<<"IM-IMAX \t\t\tC-Child\t\t\t\t15.00" << endl;
	cout<<"(More Bigger,\t\t\tA-Adult\t\t\t\t30.00" << endl;
	cout<<"\t     More Intense!)\tS-Student\t\t\t20.00 "<< endl;
	cout<<endl;
	cout<<"AT-ATMOS\t\t\tC-Child\t\t\t\t12.00" << endl;
	cout<<"(More Sound,\t\t\tA-Adult\t\t\t\t27.00" << endl;
	cout<<"\t     More Impact!)\tS-Student\t\t\t17.00" << endl;
	cout<<endl;
	cout<<"FS-FAMILY SESSION\t\tC-Child\t\t\t\t20.00" << endl;
	cout<<"(Enjoy with your family!)\tA-Adult\t\t\t\t30.00" << endl;
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	}
void Combo(){
		
	cout<< "\n\t\t\t       Combo Type" << endl;
	cout<< "-----------------------------------------------------------------------------------" << endl;
	cout<< "\tCombo Code \tFood + beverage \t\tPrice(RM)" << endl;
	cout<< "-----------------------------------------------------------------------------------" << endl;
	cout<< "\tFC01 \t\tPopcorn + Coke \t\t\t18.00" << endl;
	cout<< "\tFC02 \t\tCaramel Popcorn + Coke \t\t21.00" << endl;
	cout<< "\tFC03 \t\tChips + Coke  \t\t\t17.00" << endl;
	cout<< "\tFC04 \t\tChicken Sausage + Coke \t\t15.00" << endl;
	cout<< "\tFC05 \t\tChicken Nuggets + Coke \t\t14.00" << endl;
	cout<< "-----------------------------------------------------------------------------------\n" << endl;
	
	}
void alaCarte(){
		
	cout<< "\n\t\t\t     Ala Carte Type" << endl;
	cout<< "-----------------------------------------------------------------------------------" << endl;
	cout<< "\tFood Code \tFood only \t\tPrice(RM)" << endl;
	cout<< "-----------------------------------------------------------------------------------" << endl;
	cout<< "\tF01 \t\tPopcorn \t\t14.00" << endl;
	cout<< "\tF02 \t\tCaramel Popcorn \t17.00" << endl;
	cout<< "\tF03 \t\tChips \t\t\t9.00" << endl;
	cout<< "\tF04 \t\tChicken Sausage \t11.00" << endl;
	cout<< "\tF05 \t\tChicken Nuggets \t10.00" << endl;
	cout<< "-----------------------------------------------------------------------------------\n" << endl;
	
	}
void seatMenu(){
	cout << "\t\t\t\t\t\t\t SCREEN \t\t\t\t\t\t\t" << endl;
	cout << "\t\t [1]   [2]   [3]  \t [4]   [5]   [6]   [7]   [8]   [9]   \t  [10]   [11]   [12] " <<endl;
	cout << "\t\t [13]  [14]  [15] \t [16]  [17]  [18]  [19]  [20]  [21]  \t  [22]   [23]   [24] " <<endl;
	cout << "\t\t [25]  [26]  [27] \t [28]  [29]  [30]  [31]  [32]  [33]  \t  [34]   [35]   [36] " <<endl;
	cout << "\t\t [37]  [38]  [39] \t [40]  [41]  [42]  [43]  [44]  [45]  \t  [46]   [47]   [48] " <<endl;
	cout << "\t\t [49]  [50]  [51] \t [52]  [53]  [54]  [55]  [56]  [57]  \t  [58]   [59]   [60] " <<endl;
	cout << "\t\t [61]  [62]  [63] \t [64]  [65]  [66]  [67]  [68]  [69]  \t  [70]   [71]   [72] " <<endl; 
	cout << "\t\t [73]  [74]  [75] \t [76]  [77]  [78]  [79]  [80]  [81]  \t  [82]   [83]   [84] " <<endl;
	cout << "\t\t [85]  [86]  [87] \t [88]  [89]  [90]  [91]  [92]  [93]  \t  [94]   [95]   [96] " <<endl;
	cout << "\t\t [97]  [98]  [99] \t [100] [101] [102] [103] [104] [105] \t  [106]  [107]  [108] " <<endl;
	cout << "\t\t [109] [110] [111]\t [112] [113] [114] [115] [116] [117] \t  [118]  [119]  [120] " <<endl;
	cout << "\t\t [121] [122] [123]\t [124] [125] [126] [127] [128] [129] \t  [130]  [131]  [132] " <<endl;	
	cout << "\t\t [133] [134] [135]\t [136] [137] [138] [139] [140] [141] \t  [142]  [143]  [144] " <<endl;
	cout << "\t\t [145] [146] [147]\t [148] [149] [150] [151] [152] [153] \t  [154]  [155]  [156] " <<endl;
	
}
void merchmenu(){
		
	cout<< "\n\t\t\tMerchandise Type" << endl;
	cout<< "-----------------------------------------------------------------------------------" << endl;
	cout<< "\tMerchandise Code \tMerchandise Name \t\tPrice(RM)" << endl;
	cout<< "-----------------------------------------------------------------------------------" << endl;
	cout<< "\tA \t\t\tSpider-man toy \t\t\t50.00" << endl;
	cout<< "\tB \t\t\tGodzilla & Kong pillow \t\t100.00" << endl;
	cout<< "\tC \t\t\tJohn Wick wig \t\t\t30.00" << endl;
	cout<< "-----------------------------------------------------------------------------------\n" << endl;
	}
void minMaxTicket(int X, int Y, int Z){
    int ticket[] = {X, Y, Z};//x=student, y=child, z=adult
    int max = -1;
    int min = 100;
    int index = 0;
    
	//for statement to find min and max
    for (index = 0; index < 3; index++) {
        if (ticket[index] > max)
            max = ticket[index];

        if (ticket[index] < min)
            min = ticket[index];
    }
    
    if (min == ticket[0])//x
        cout << "\n | \t\tMINIMUM TICKET PURCHASED[STUDENT]: "<<min<<endl;
    else if (min == ticket[1])//y
        cout << "\n | \t\tMINIMUM TICKET PURCHASED [CHILD] : "<<min<<endl;
    else if (min == ticket[2])//z
        cout << "\n | \t\tMINIMUM TICKET PURCHASED [ADULT] : "<<min<<endl;

    if (max == ticket[0])
        cout << "\n | \t\tMAXIMUM TICKET PURCHASED[STUDENT]: "<<max<<endl;
    else if (max == ticket[1])
        cout << "\n | \t\tMAXIMUM TICKET PURCHASED [CHILD] : "<<max<<endl;
    else if (max == ticket[2])
        cout << "\n | \t\tMAXIMUM TICKET PURCHASED [ADULT] : "<<max<<endl;
}
int functionTotal(int a, int b, int c, int d, int e){
	
	int sum = 0;
	
	sum = a + b + c + d + e;
	
	return sum;
}
void paymentMenu(){
	cout << "\n-------------------------Enter your payment method--------------------------"<<endl;
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	cout<<"Payment code\t Payment Method\t\t Benefit discounts"<<endl;
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	cout<<"    D\t\tDebit/Credit Card\t\t: 3% "<<endl;
	cout<<"    T\t\tTouch & Go eWallet\t\t: 5% "<<endl;
	cout<<"    C\t\tCash\t\t\t\t: 0% "<<endl;
	cout<<"-----------------------------------------------------------------------------------"<<endl;
}
double avg(double &i, int u) {
	
	double average = 0.0;
	
    average = i / u;
    
    cout << fixed << setprecision(2);
    cout << "Average of user purchased : RM" << average << endl;
    
    return average;
}
