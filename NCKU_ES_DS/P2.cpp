#include<iostream>

using namespace std;

int main(){
    FILE *fp;
    fp = fopen("test_topo.txt", "r");
    if(fp!=NULL){
        int martix_max = 0;
        fscanf(fp,"%d", &martix_max);
        
        int graph_matrix[martix_max][martix_max];
        
        int i = 0, j = 0,k,a;
        for (i = 0; i < martix_max;i++){
            for (j = 0; j <martix_max;j++)
                fscanf(fp,"%d", &graph_matrix[i][j]);
        }
        
//        for (i = 0; i < martix_max;i++){
//            for (j = 0; j <martix_max;j++)
//                printf("%d ", graph_matrix[i][j]);
//            printf("\n");
//        }


        ///////////////////////////
		//complete the code below//
		///////////////////////////
        printf("topological sort: ");
        
        
        

    }else{
        printf("file do not exist");
        fclose(fp);
    }
    fclose(fp);
}
