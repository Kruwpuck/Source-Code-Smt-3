import java.util.Arrays;
import java.util.Scanner;

public class matrix {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int rangeMatrix = Integer.parseInt(input.nextLine());
        int array1 [][] = new int[rangeMatrix][rangeMatrix];
        int array2 [][] = new int[rangeMatrix][rangeMatrix];
        int arrayHasil [][] = new int[rangeMatrix][rangeMatrix];
        int baris = 0;
        int kolom = 0;
        //input Untuk Matrix
        for(int z = 0 ; z < Math.pow(rangeMatrix, 2) * 2;z++){
            int inputUser = Integer.parseInt(input.nextLine());
            if(kolom == rangeMatrix){
                kolom = 0;
                baris++;
            }
            if(baris == rangeMatrix){
                baris = 0;
                kolom = 0;
            }
            if(z < Math.pow(rangeMatrix, 2) && (baris < inputUser && kolom < inputUser)){
                array1[baris][kolom] = inputUser;
                System.out.println("baris");
                System.out.println(baris);
                System.out.println("kolom");
                System.out.println(kolom);
                System.out.println(Arrays.deepToString(array1)) ;
                kolom++;
                
            }
            else{
                array2[baris][kolom] = inputUser;
                System.out.println(Arrays.deepToString(array2)) ;
                kolom++;
            }
        }
       
        //perkalian matrixnya
        for(int i = 0 ; i < array1.length;i++){
            for(int z = 0 ; z < array1.length;z ++){
                // arrayHasil[i][kolom] == array1[i][z] * array2[]
                for(int w = 0 ; w < array1.length;w++){
                    arrayHasil[i][z] += array1[i][w] * array2[w][z]; 
                }
            }
        }
        System.out.println(Arrays.deepToString(arrayHasil)) ;

        
        
    }
}