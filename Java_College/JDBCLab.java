
/*
 * @author Brett Kriz
 * @author Mike Wallace
 */

import java.sql.*;

public class JDBCLab {
	Connection conn = null;
	Statement stmt = null;
	ResultSet rs = null;
	
	public int connectDb(){
		try{
			conn = 
DriverManager.getConnection("jdbc:mysql://classdb.it.mtu.edu/bakriz","bakriz","password");
		} catch (SQLException e){
			System.out.println(e.getMessage());
			e.printStackTrace();
			return 1;

		}
		return 0;
	}
	
	public void disconnect (){
		try{
			conn.close();
		}
		catch (SQLException ex){
			System.out.println("SQLException: " + ex.getMessage());
			System.out.println("SQLState: " + ex.getSQLState());
			System.out.println("VendorError: " + ex.getErrorCode());
		}
	}
	
	public static void main (String args[]){
// ******************************************************************
		JDBCLab l = new JDBCLab();
		l.connectDb();
		l.select();
		l.withdraw("a' or account_number = 'a001'#", 10); // ' or account_number = 'a001'#
		l.select();
		l.disconnect();
// ****************************************************************************
	}
	
	public void select(){
		Statement s = null;
		ResultSet r = null;
		
		try {
			s = conn.createStatement();
			r = s.executeQuery("SELECT * FROM lab2_account");
			while (r.next()){
				System.out.println(r.getString(1) + "," + r.getString(2));
			}
		}
		catch (SQLException ex){
			System.out.println("SQLException: " + ex.getMessage());
			System.out.println("SQLState: " + ex.getSQLState());
			System.out.println("VendorError: " + ex.getErrorCode());
		}
	}
	
	public int withdraw(String acc, double amt){
		PreparedStatement s;
		ResultSet r;
		int rowcount;
		
		try{
			conn.setAutoCommit(false);
			conn.setTransactionIsolation(conn.TRANSACTION_SERIALIZABLE);
		}catch (SQLException ex){
			ex.printStackTrace();
			return 0;
		}
		
		try{
			
			String t1 = "select balance from lab2_account";
			String t2 = "UPDATE lab2_account SET balance = balance - " + amt + " WHERE account_number = ?"; //+ acc + "' ";
			s = conn.prepareStatement(t2);
			s.setString(1, acc);
			
			
			rowcount = s.executeUpdate();
			if (rowcount != 1){
				System.out.println("SOME THINGS WRONG: updating " + rowcount + "Rows");
				conn.rollback();
			}else{
				System.out.println("Update " + rowcount + "ROWS");
				conn.commit();
			}
			
		}catch (SQLException ex){
			System.out.println("SQLException: " + ex.getMessage());
			System.out.println("SQLState: " + ex.getSQLState());
			System.out.println("VendorError: " + ex.getErrorCode());
		}
		return 1;
	}
}

