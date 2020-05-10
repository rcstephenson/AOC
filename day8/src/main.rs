// AOC day8 09.05.20
use std::io::{self, Read};

const HEIGHT: usize = 6;
const WIDTH: usize = 25;

fn main() {

    // read input 
    let x = get_input();
    let num_layers: usize = x.len() / (HEIGHT*WIDTH);

    //parse input 
    let mut layers: Vec<Vec<String>> = Vec::new();
    let mut max_match: (usize,usize) = (0,150);
    let x = x.chars().collect();
    for row in 0..num_layers {
        let layer = get_layer(row, &x);
        let mut s = 0;
        for n in &layer {
            s += n.matches("0").count();
        }
        if s < max_match.1 {
            max_match = (row,s);
        }
        layers.push(layer);
    }
    println!("Part 1 Solution:");

    //compute ones and twos 
    let mut one = 0;
    let mut two = 0;
    for ij in &layers[max_match.0] {
        for c in ij.chars() {
            let num = c.to_string().parse::<i32>().unwrap();
            if num == 1 { one+=1; }
            if num == 2 { two+=1; }
        }
    }

    
    // display result
    println!("1s: {}\n2s: {}\nProd: {}", one, two, one*two);


    //----------------part2--------------------------------
    let mut ans = vec![vec!['2'; 25]; 6];
    //println!("{:?}",ans);
    for l in &layers {
        for j in 0..6 {
            let c: Vec<char> = l[j].chars().collect();
            for i in 0..25 {
                if ans[j][i] == '2' {
                    if c[i] != '2' {
                        if c[i] == '1'{
                            ans[j][i] = '@';
                        } if c[i] == '0'{
                        ans[j][i] = '_';
                        }
                    }
                } 
            }
        }
    }
    println!("\nPart 2 solution: ");
    for i in 0..6 {
        for j in 0..25 {
            print!("{}",ans[i][j])
        }
        println!("");
    }

}

fn get_input() -> String {
    let mut input = String::new();
    io::stdin().lock().read_to_string(&mut input).unwrap();
    return input.trim().to_string();
}

fn get_layer(n: usize, input:  &Vec<char>) -> Vec<String> {
        let mut out: Vec<String> = vec!();
            for i in 0..HEIGHT {
            out.push(input[(n*HEIGHT+i)*WIDTH..(n*HEIGHT+i+1)*WIDTH].iter().collect());
        }
    out
}
