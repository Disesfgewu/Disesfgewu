library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity Conponent is
    port( 
        a , b : in std_logic_vector (7 downto 0);
        s : in std_logic_vector (2 downto 0);
        c : in std_logic;
        f : out std_logic_vector (7 downto 0)
    );
end Conponent;

architecture behavior of Conponent is
begin
      process(a, b, c, s)
      begin
      case s is
        when "000" => f <= "00000000";
        when "001" => f <= std_logic_vector (unsigned(b) - unsigned(a) + unsigned("0000000" & c) - 1);
        when "010" => f <= std_logic_vector (unsigned(a) - unsigned(b) + unsigned("0000000" & c) - 1);
        when "011" => f <= std_logic_vector (unsigned(a) + unsigned(b) + unsigned("0000000" & c) );
        when "100" => f <= a XOR b;
        when "101" => f <= a OR b;
        when "110" => f <= a AND b;
        when others => f <= "11111111";
	  end case;
    end process;
end behavior;
