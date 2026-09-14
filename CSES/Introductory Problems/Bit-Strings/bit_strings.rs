use std::io::Read;

const MOD: i32 = 1_000_000_007;

fn main() {
    let mut read = String::with_capacity(16);
    std::io::stdin().lock().read_to_string(&mut read).unwrap();
    let n = read.trim().parse::<i32>().unwrap();
    let mut ans = 1;
    for _ in 0..n {
        ans = (ans << 1) % MOD;
    }
    println!("{}", ans);
}
