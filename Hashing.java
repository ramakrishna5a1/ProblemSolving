class Hashing{
	private int SIZE = 10;
	private int[] hashTable;
	
	public Hashing(int size){
		this.SIZE = size;
		hashTable = new int[SIZE];
	}
	public Hashing(){
		hashTable = new int[SIZE];
	}
	
	public boolean insertData(int key){
		int pos = SIZE%key;
	}
	
	public void getData(){
	
	}
	
	public boolean containsKey(int key){
		
	}
}
