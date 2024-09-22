#include <iostream>
#include <algorithm>//to shorten my code i used the "sort" function
#include <math.h>//for power and sqrt functions
using namespace std;
int n;//n is a globally defined variable since i access it in main and my class :p
class DataAnalyzer
{
    private://private members
    float* SortedData = new float[n];//dynamically allocated the memory for sorted data to save space
    float sum=0;
    bool sorted = false;
    public:
    float* dataSet = new float[n];// a public member that user can access from main 
    float mean=0, median=0, Q1=0, Q2=0, Q3=0, variance=0, standardDeviation=0;
    //method variables initialized to zero to avoid garbage values
    
    void enterData()//class method to get user input into data set array
    {
        cout<<"\nEnter Data\n";
        for(int i = 0; i<n; i++)
        {
            cout<<i+1<<". ";
            cin>>dataSet[i];
        }
    }
    bool isSorted(float dataSet[], int start, int size)
    //class method checks if dataset is sorted
    {
        if(start==size)
        {
            return true;
        }
        else if(dataSet[start]<=dataSet[start+1])
        {
            return isSorted(dataSet, start+1, size);

        }
        else
        {
            return false;
        }
    }
    void sortData()
    {
        sorted = isSorted(dataSet, 0, n-1);//sorted is updated if the dataset is already sorted
        if(!sorted)//if not sorted
        {
            sort(dataSet, dataSet + n); //in built sort function
            for(int i = 0; i<n; i++)
            {
                SortedData[i] = dataSet[i];//copying elements to sorted data 
            }
        }
        else
        {
            for(int i = 0; i<n; i++)
            {
                SortedData[i] = dataSet[i];//copying elements to sorted data
            }
        }
        
    }
    void calculateMean()//simple mean calculation
    {
        sum = 0;
        for(int i = 0; i<n; i++)
        {
            sum = sum + dataSet[i];
        }

         mean = sum/n;
         cout<<"| Mean | "<<"==>"<<" | "<<mean<<" | "<<endl;
    }
    void calculateMedian()//calculates median on the basis of an even or odd size
    {
    
        sortData();
        if(n%2 == 0)
        {
            int x = (n)/2;
            median = (dataSet[x]+dataSet[x-1])/2;
        }
        else
        {
            median = dataSet[(n-1)/2];
        }
        cout<<"| Median | "<<"==>"<<" | "<<median<<" | "<<endl;

    }
    void calculateMode()//mode calculations
    {
        int count = 1;
        float modeValue = SortedData[0];
        int maxFrequency = 0;
        for(int i = 0; i<n; i++)
        {
            if(SortedData[i]==SortedData[i+1])
            {
                count++;
                if(count>maxFrequency)
                {
                    maxFrequency = count;
                    modeValue = SortedData[i];
                }
                
            }
            else
            {
                count = 1;
            }
             
            
        }
        if(count==1 && maxFrequency==0)
        {
            cout<<"All values in the dataset have same frequencies!"<<endl;
        }
        else
        {
            cout<<"| Mode Value | "<<"==>"<<" | "<<modeValue<<" | "<<endl;
        }
        

    }
    void calculateVariance()//calculates variance and standard deviation
    {
        float varianceSum = 0;
        for(int i = 0; i<n; i++)
        {
             varianceSum = varianceSum + (pow((dataSet[i]-mean), 2));
        }
        variance = varianceSum/n;
        standardDeviation = sqrt(variance);
        cout<<"| Variance | "<<"==>"<<" | "<<variance<<" | "<<endl;
       cout<<"| Standard Deviation | "<<"==>"<<" | "<<standardDeviation<<" | "<<endl;

    }
    void calculateQuartiles()
    {
        //quartile calculation may not be perfect, used self developed formulas
        Q2 = median;
        if(n%2 == 0)
        {
            if((n/2)%2 == 0)
        {
            int y = n/4;
            Q1 = (dataSet[y] + dataSet[y-1])/2;
            Q3 = (dataSet[(n/2) + y] + dataSet[(n/2) + (y-1)])/2;
        }
        else
        {
            int z = (n-2)/4;
            Q1 = dataSet[(n/2)-1-z];
            Q3 = dataSet[(n/2)+z];
        }

        }
        else
        {
            if((n/2)%2 == 0)
            {
                Q1 = (dataSet[(n+1)/4] + dataSet[(n+1)/4 - 1])/2;
                Q3 = (dataSet[(3*n - 1)/4] + dataSet[((3*n - 1)/4)+1])/2;


            }
            else
            {
                Q1 = dataSet[(n-3)/4];
                Q3 = dataSet[(3*n-1)/4];

            }
        }
        cout<<"| Q1 | "<<"==>"<<" | "<<Q1<<" | "<<endl;
        cout<<"| Q2 | "<<"==>"<<" | "<<Q2<<" | "<<endl;
        cout<<"| Q3 | "<<"==>"<<" | "<<Q3<<" | "<<endl;
        
    }
    void calculateCorrelationCoefficient(DataAnalyzer obj2, DataAnalyzer obj, int size)
    {//calculations for the correlaton coefficient
        float covarianceSum=0;

        for(int i = 0; i<size; i++)
        {
            covarianceSum = covarianceSum + ((obj.dataSet[i]- obj.mean)*(obj2.dataSet[i] - obj2.mean));
        }

        cout<<"| Covariance Sum | "<<"==>"<<" | "<<covarianceSum<<" | "<<endl;
        float correlationCoefficient = covarianceSum/((size-1)*((sqrt(obj.variance)) * (sqrt(obj2.variance))));
        cout<<"| Correlation Coefficient | "<<"==>"<<" | "<<correlationCoefficient<<" | "<<endl;
        

    }

    void clearMemory()//deallocating memory using a function
    {
        delete[] SortedData;
        delete[] dataSet;
    }
// not used constructors or destructors
};
int main()
{
    
    int x, number, displayIndex, j, numberA, numberB;//needed variables
    cout<<"MENU:"<<endl;
    cout<<"1. Enter Numerical Data in Data Set\n2. Display Statistical Calculations for Data Set\n3. Calculate Correlation Coefficient Between Any Two Data Sets\n4. Exit\n";
    cout<<"Enter Your Choice: "; cin>>x;
    cout<<"\nMAXIMUM DATA SETS THAT CAN BE ENTERED ARE 10";//can enter upto 10 datasets, array of objects
    DataAnalyzer dataSet[10];
    cout<<"\nHow Many Data Sets Do You Want To Enter?  ";
    cin>>number;
    while(x!=4)
    {
        switch(x)
        {
            case 1:
            cout<<"\nEnter the general size of your data sets: ";cin>>n;//datasets of similar sizes to simplify 
            for(int i = 0 ; i< number; i++)
            {
                cout<<"\nEntering Data for Data Set "<<i+1<<"...";
                dataSet[i].enterData();
            }
            break;
            case 2:
            cout<<"Enter the Data Set Number: ";cin>>displayIndex;
            j = displayIndex-1;
            cout<<"Displaying Statistical Calculations for Data Set "<<displayIndex<<"..."<<endl;
            dataSet[j].calculateMean();cout<<endl;    
            dataSet[j].calculateMedian();cout<<endl; 
            dataSet[j].calculateQuartiles();cout<<endl; 
            dataSet[j].calculateMode();cout<<endl; 
            dataSet[j].calculateVariance();cout<<endl; //calling functions for the object wanted
            break;
            case 3:
            if(number>=2)//when more than 1 datasets
            {
                cout<<"Enter Data Set A Number:  ";
                cin>>numberA;
                cout<<"Enter Data Set B Number:  ";
                cin>>numberB;
                cout<<"Details  of data set "<<numberA<<endl;
                dataSet[numberA-1].calculateMean();
                dataSet[numberA-1].calculateVariance();
                cout<<"Details  of data set "<<numberB<<endl;
                dataSet[numberB-1].calculateMean();
                dataSet[numberB-1].calculateVariance();
                dataSet[numberB-1].calculateCorrelationCoefficient(dataSet[numberB-1], dataSet[numberA-1], n);
            }
            else
            {
                cout<<"ERROR---Insufficient datasets"<<endl;
            }
            break;
            case 4:
            break;
            default:
            cout<<"Enter Valid Choice"<<endl;
        }
        cout<<"\nMENU:"<<endl;
        cout<<"1. Enter Numerical Data in Data Set\n2. Display Statistical Calculations for Data Set\n3. Calculate Correlation Coefficient Between Any Two Data Sets\n4. Exit\n";
        cout<<"Enter Your Choice: "; cin>>x;
        
    } 


}