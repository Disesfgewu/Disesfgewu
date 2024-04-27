library ieee;
use ieee.std_logic_1164.all;

entity tb_Conponent is
end tb_Conponent;

architecture tb of tb_Conponent is

    component Conponent
        port (b   : in std_logic_vector (7 downto 0);
              s   : in std_logic;
              rst : in std_logic;
              clk : in std_logic;
              f   : out std_logic_vector (7 downto 0));
    end component;

    signal b   : std_logic_vector (7 downto 0);
    signal s   : std_logic;
    signal rst : std_logic;
    signal clk : std_logic;
    signal f   : std_logic_vector (7 downto 0);

begin

    dut : Conponent
    port map (b   => b,
              s   => s,
              rst => rst,
              clk => clk,
              f   => f);

    stimuli : process
    begin
        -- EDIT Adapt initialization as needed
        b <= (others => '0');
        s <= '0';
        clk <= '0';

        -- Reset generation
        -- EDIT: Check that rst is really your reset signal
        rst <= '0';
        clk <= '1';
        b <= x"05";
        s <= '0';
        wait for 10 ns;
        rst <= '0';
        clk <= '1';
        b <= x"03";
        s <= '0';
        wait for 10 ns;
        rst <= '0';
        clk <= '1';
        b <= x"03";
        s <= '1';
        wait for 10 ns;
        rst <= '0';
        clk <= '1';
        b <= x"02";
        s <= '1';
        wait for 10 ns;
        rst <= '1';
        wait for 10 ns;

        -- EDIT Add stimuli here

        wait;
    end process;

end tb;

-- Configuration block below is required by some simulators. Usually no need to edit.

configuration cfg_tb_Conponent of tb_Conponent is
    for tb
    end for;
end cfg_tb_Conponent;