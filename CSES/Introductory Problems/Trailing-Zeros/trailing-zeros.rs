use std::io::BufRead;
use std::io::Write;
 
fn solution(n: &i32) -> i32 {
    let mut count = 0;
    let mut divider = 5;
    loop {
        count += n / divider;
        divider *= 5;
        if divider > *n {
            break;
        }
    }
    count
}
 
fn main() {
    let mut reader = std::io::stdin().lock();
    let mut writer = std::io::stdout().lock();
    let mut buf = String::new();
    reader.read_line(&mut buf).unwrap();
    let n: i32 = buf.trim().parse().unwrap();
    let res = solution(&n);
    if writeln!(writer, "{}", res).is_err() {
        println!("{}", res);
    }
    if writer.flush().is_err() {
        println!("{}", res);
    }
