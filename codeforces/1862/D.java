import java.io.*;
import java.math.*;

public class Solution {

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            BigDecimal n = new BigDecimal(br.readLine());

            BigDecimal answer = n.multiply(new BigDecimal("8"))
                                 .add(BigDecimal.ONE)
                                 .sqrt(MathContext.DECIMAL128)
                                 .add(BigDecimal.ONE)
                                 .divideToIntegralValue(new BigDecimal("2"));
            // System.out.println(answer);

            System.out.println(
                    answer.add(
                        n.subtract(
                            answer.subtract(BigDecimal.ONE)
                                  .multiply(answer)
                                  .divide(BigDecimal.ONE.add(BigDecimal.ONE))
                        )
                    ).toBigInteger()
                );
        }

    }
}
