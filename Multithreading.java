class Movie extends Thread{
    int tickets;
    Movie(int tickets){
        this.tickets = tickets; 
    }
    public void run(){
        if(tickets > 0){
            try{
                Thread.sleep(1500);
                tickets--;
                System.out.println("Ticket booked by "+Thread.currentThread().getName());
            }
            catch (Exception e){
            }
        }
        else{
            System.out.println("Sorry House Full "+Thread.currentThread().getName());
        }
    }
}



public class Multithreading {
    public static void main(String args[]){
        Movie m = new Movie(1);
        Thread t1 = new Thread(m);
        Thread t2 = new Thread(m);
        t1.setName("Hemant");
        t2.setName("Rishabh");
        t1.start();
        t2.start();
    }
}
