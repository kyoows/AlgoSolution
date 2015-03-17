#include <cstdio>

const char* ans[13][13] = {
  {"", "", "1/1", "1/2", "1/3", "1/4", "1/5", "1/6", "1/7", "1/8", "1/9", "1/10", "1/11"},
  {"", "", "2/1", "3/4", "4/9", "5/16", "6/25", "7/36", "8/49", "9/64", "10/81", "11/100", "12/121"},
  {"", "", "6/1", "3/2", "20/27", "15/32", "42/125", "7/27", "72/343", "45/256", "110/729", "33/250", "156/1331"},
  {"", "", "26/1", "33/8", "44/27", "115/128", "366/625", "91/216", "776/2401", "531/2048", "470/2187", "913/5000", "2316/14641"},
  {"", "", "150/1", "15/1", "380/81", "285/128", "4074/3125", "70/81", "10440/16807", "1935/4096", "7370/19683", "957/3125", "41340/161051"},
  {"", "", "1082/1", "273/4", "4108/243", "3535/512", "11334/3125", "2149/972", "174728/117649", "34983/32768", "142870/177147", "7909/12500", "905772/1771561"},
  {"", "", "9366/1", "1491/4", "17780/243", "26355/1024", "189714/15625", "3311/486", "3525192/823543", "381465/131072", "1114190/531441", "98637/62500", "23961756/19487171"},
  {"", "", "94586/1", "38001/16", "269348/729", "458555/4096", "3706518/78125", "285929/11664", "11870648/823543", "9725787/1048576", "30495890/4782969", "5760733/1250000", "742682316/214358881"},
  {"", "", "1091670/1", "17295/1", "4663060/2187", "1139685/2048", "82749954/390625", "220430/2187", "319735800/5764801", "35420535/1048576", "953934190/43046721", "6008937/390625", "26317104060/2357947691"},
  {"", "", "14174522/1", "566733/4", "10091044/729", "25492435/8192", "2078250726/1953125", "1359337/2916", "9686934584/40353607", "1160703963/8388608", "3728765410/43046721", "451103521/7812500", "1048626960492/25937424601"},
  {"", "", "204495126/1", "2579313/2", "218374420/2187", "316786305/16384", "11598884682/1953125", "5239157/2187", "326084753016/282475249", "21129845715/33554432", "145739620510/387420489", "940586163/3906250", "46417727304156/285311670611"},
  {"", "", "3245265146/1", "103302843/8", "5198287172/6561", "8660538005/65536", "356040257982/9765625", "710791123/52488", "12074605510328/1977326743", "846255118437/268435456", "6266014655810/3486784401", "86294277091/78125000", "205472305173156/285311670611"},
  {"", "", "56183135190/1", "141045450/1", "44997259580/6561", "64573144545/65536", "11922594787194/48828125", "547911910/6561", "487759711378680/13841287201", "9243544978395/536870912", "97966715016170/10460353203", "269906258622/48828125", "10914811650686580/3138428376721"}
};

int main() {
  int a, b;

  scanf("%d%d", &a, &b);
  if (b == 1) {
    puts("infinity");
  } else {
    puts(ans[a][b]);
  }

  return 0;
}

/*
N = 12

c = Array.new(N + 1){ [0] * (N + 1) }

0.upto(N) do |i|
  c[i][0] = 1
  1.upto(i) do |j|
    c[i][j] = c[i - 1][j - 1] + c[i - 1][j]
  end
end

c.each do |i|
  p i
end

ans = Array.new(N + 1){ [nil] * (N + 1) }

2.upto(N) do |b|
  ans[0][b] = Rational(1, b - 1)
# ans[1][b] = Rational(b, (b - 1) ** 2)
end

1.upto(N) do |a|
  2.upto(N) do |b|
    ans[a][b] = Rational(1)
    0.upto(a - 1) do |i|
      ans[a][b] += ans[i][b] * c[a][i]
    end
    ans[a][b] /= b - 1
  end
end

ans.each do |i|
  p i
end

ans.each do |i|
  puts '{' + i.map{|j| j.to_s.inspect} * ', ' + '},'
end
*/