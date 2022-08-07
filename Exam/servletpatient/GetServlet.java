import com.mysql.jdbc.ResultSet;
import com.mysql.jdbc.Statement;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/GetServlet")
public class GetServlet extends HttpServlet {

  private static final long serialVersionUID = 1L;

  public GetServlet() {
    super(); // TODO Auto-generated
  }

  protected void doGet(
    HttpServletRequest request,
    HttpServletResponse response
  )
    throws ServletException, IOException {
    request.getRequestDispatcher("/index.html").forward(request, response);
  }

  protected void doPost(
    HttpServletRequest request,
    HttpServletResponse response
  )
    throws ServletException, IOException {
    try {
      Class.forName("com.mysql.jdbc.Driver");
      Connection con = DriverManager.getConnection(
        "jdbc:mysql://localhost:3306/java",
        "root",
        "root"
      );
      Statement stmt = (Statement) con.createStatement();
      ResultSet rs = (ResultSet) stmt.executeQuery(
        "select * from PatientRecords"
      );
      String s = "{\n";
      while (rs.next()) {
        s += rs.getString(1) + "\n";
        s += rs.getString(2) + "\n";
        s += rs.getString(3) + "\n";
        s += rs.getString(4) + "\n";
        s += rs.getString(5) + "\n";
        s += rs.getString(6) + "\n}\n";
      }
      request.setAttribute("data", s);
    } catch (Exception e) {
      System.out.println(e);
    }
    request.getRequestDispatcher("/data.jsp").forward(request, response);
  }
}
