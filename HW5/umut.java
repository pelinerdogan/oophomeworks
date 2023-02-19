import java.util.Scanner;

class h {
    public static void main(String[] args) {
        String alphabet = "abcçdefgğhiıjklmnoöprsştuüvwxyz";

        Scanner s = new Scanner(System.in);

        System.out.println("Enter the first city : ");
        String fcity = s.nextLine();
        fcity.toLowerCase();

        System.out.println("Enter the second city : ");
        String scity = s.nextLine();
        scity.toLowerCase();

        System.out.println("Enter the third city : ");
        String tcity = s.nextLine();
        tcity.toLowerCase();

        boolean founded = false;

        char fcityl = fcity.charAt(0);
        char scityl = scity.charAt(0);
        char tcityl = tcity.charAt(0);

        String[] arr = new String[3];
        int i = 0;
        int index1 = 0, index2 = 0, index3 = 0;
        while (founded == false) {

            if (alphabet.charAt(i) == fcityl) {

                index1 = i;

                founded = true;
            } else
                i++;

        }

        founded = false;

        i = 0;

        while (founded == false) {

            if (alphabet.charAt(i) == scityl) {

                index2 = i;

                founded = true;
            } else
                i++;

        }

        founded = false;

        i = 0;

        while (founded == false) {

            if (alphabet.charAt(i) == tcityl) {

                index3 = i;

                founded = true;
            } else
                i++;

        }

        
        founded = false;

        i = 0;

        System.out.println("hi 1" );
        if (index1 == index2 && index3 < index1) {
            
            Boolean different = false;
            int k = 0;
            while (different == false) {

                if (fcity.charAt(k) != scity.charAt(k)) {
                     fcityl =fcity.charAt(k); 
                     scityl =scity.charAt(k); 
                     
                    while (founded == false) {

                        if (alphabet.charAt(i) == fcityl) {

                            index1 = i;

                            founded = true;
                        } else
                            i++;

                    }

                    founded = false;

                    i = 0;
                    while (founded == false) {

                        if (alphabet.charAt(i) == scityl) {

                            index2 = i;

                            founded = true;
                        } else
                            i++;

                    }
                    different=true;
                }

            }

            if(index1>index2){
             arr[0]=tcity;
             arr[1]=fcity;
             arr[2]=scity;

            }
            else{
                arr[0]=tcity;
                arr[1]=scity;
                arr[2]=fcity;
   
            }

        }

        if (index1 == index3 && index2 < index1) {
            Boolean different = false;
            int k = 0;
            while (different == false) {

                if (fcity.charAt(k) != tcity.charAt(k)) {
                     fcityl =fcity.charAt(k); 
                     tcityl =scity.charAt(k); 
                     
                    while (founded == false) {

                        if (alphabet.charAt(i) == fcityl) {

                            index1 = i;

                            founded = true;
                        } else
                            i++;

                    }

                    founded = false;

                    i = 0;
                    while (founded == false) {

                        if (alphabet.charAt(i) == tcityl) {

                            index3= i;

                            founded = true;
                        } else
                            i++;

                    }
                    different=true;
                }

            }

            if(index1>index3){
             arr[0]=scity;
             arr[1]=fcity;
             arr[2]=tcity;

            }
            else{
                arr[0]=scity;
                arr[1]=tcity;
                arr[2]=fcity;
   


            }

        }

        if (index3 == index2 && index1 < index2) {
            System.out.println("hi 1" );
            Boolean different = false;
            int k = 0;
            while (different == false) {
                System.out.println("hi 2" );

                if (tcity.charAt(k) != scity.charAt(k)) {
                     tcityl =tcity.charAt(k); 
                     scityl =scity.charAt(k); 
                     
                    while (founded == false) {

                        if (alphabet.charAt(i) == tcityl) {

                            index3 = i;

                            founded = true;
                        } else
                            i++;

                    }

                    founded = false;

                    i = 0;
                    while (founded == false) {

                        if (alphabet.charAt(i) == scityl) {

                            index2 = i;

                            founded = true;
                        } else
                            i++;

                    }
                    different=true;
                }

            }

            if(index3>index2){
             arr[0]=fcity;
             arr[1]=tcity;
             arr[2]=scity;

            }
            else{
                arr[0]=fcity;
                arr[1]=scity;
                arr[2]=tcity;
   
            }

        }
        System.out.println("hi 5" );

        System.out.println("alphabetic list: ");
        for(int j = 0; j<3 ; j++){

            System.out.println(arr[j]);
        }
    }
}