import java.net.InetAddress;
import org.acplt.oncrpc.*;

public class x2y_conv {

	public static void main(String args[]) {
		if(args.length != 2) {
			System.err.println("USAGE : java x2y_conv.class <value> <hostname>");
			System.exit(1);
		}

		try {
			InetAddress host = InetAddress.getAllByName(args[1])[0];
			x2yClient server = new x2yClient(host, OncRpcProtocols.ONCRPC_TCP);

			double returnValue = server.convert_x2y_3(Float.parseFloat(args[0]));

			System.out.println(args[0] + " X font " + returnValue + " Y.");

		} catch(Exception e) {

		}

	}
}