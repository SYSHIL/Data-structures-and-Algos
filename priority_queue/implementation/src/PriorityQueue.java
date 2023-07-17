import java.util.ArrayList;

public class PriorityQueue {
    private ArrayList<Integer> data;

    public PriorityQueue() {
        this.data = new ArrayList<>();
        System.out.println("Initialized priority queue");
    }

    public void add(int value){
        data.add(value);
        upheapify(data.size()-1);
    }
    public int poll(){
       int value = data.get(0);
       swap(0,data.size()-1);
       data.remove(data.size()-1);
       downHeapify(0);
       return value;
    }

    public int peek(){
        return data.get(0);
    }

    private void downHeapify(int idx){
        int mini = idx;
        int li = 2*idx+1;
        int ri = 2*idx+2;
        if(li<data.size() && data.get(idx)>data.get(li)){
            mini = li;
        }
        if(ri<data.size() && data.get(idx)>data.get(ri)){
            mini = ri;
        }
        if(mini!=idx){
            swap(idx,mini);
            downHeapify(mini);
        }
    }
    private void upheapify(int idx){
        if(idx==0){
            return;
        }
        int pi = (idx-1)/2;
        if(data.get(idx)<data.get(pi)){
            swap(idx,pi);
            upheapify(pi);
        }
    }
    private void swap(int i,int j){
        int ithElement = data.get(i);
        int jthElement = data.get(j);
        data.set(i,jthElement);
        data.set(j,ithElement);
    }

}
