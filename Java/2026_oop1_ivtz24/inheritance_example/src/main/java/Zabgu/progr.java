public interface Programmer{

	void write_code();

} 


public class JavaProgrammer implements Programmer{

	@Override
	void write_code(){
		/// 
	}
	
} 

public class RustProgrammer implements Programmer{

	@Override
	void write_code(){
		/// 
	}
	
} 


public static void main(){

	Programmer p1 = new RustProgrammer();
	Programmer p2 = new JavaProgrammer();

	p1.write_code();
	p2.write_code();
}