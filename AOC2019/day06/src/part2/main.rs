// Day 6 Advent of Code
// Part. 2 - 25 April 2020
use std::fs::File;
use std::process;
use csv;

type Record = (String, String); // Data Type for "object)orbit"

fn main() {
	println!("Day6, Part 2 Code:");
	let data: Vec<Record>;
	match run("input.txt") {
		Ok(out) => {
			data = out.clone();
		}
		Err(err) => {
			println!("{}", err);
			process::exit(1);
		}
	}
	let mut obj = Vec::new();
	let mut orb = Vec::new();
	for d in &data {
		obj.push(&d.0);
		orb.push(&d.1);
	}
	/* let mut sol = 0i32;
	for x in orb {
		let i = get_chain_len(x, &data, 0i32);
		sol += i;
	}
	println!("Part 1: {}",sol);
	*/
	// println!("Path Test: {:?}", get_path("YOU", vec![String::from("YOU")],&data,0i32).1); //400~450
	let (x,a) = get_path("YOU", vec![String::from("YOU")],&data,0i32);
	let (y,b) = get_path("SAN", vec![String::from("SAN")],&data,0i32);
	println!("Length from COM to YOU,SANTA: {}, {}",x,y);
	
	let mut ii = 0;
	for A in &a {
		for B in &b {
			if A==B{
				ii+=1;
				// println!("{}", A);
				break; 
			}
		}	
	}
	println!("Matches: {}",ii);
	println!("Path Length: {}", x+y-2*ii);
	println!("EOF.");
}

fn run(fname: &str) -> Result<Vec<Record>,csv::Error>{
    let f = File::open(fname).expect("Unable to open file");
	let mut rdr = csv::ReaderBuilder::new()
		.delimiter(b')')
		.has_headers(false)
		.from_reader(f);
	let mut out: Vec<Record> = Vec::new();
	for result in rdr.deserialize() {
		let record: Record = result?;
		out.push(record);	
	}
	Ok(out)
}


fn get_path(orb: &str, found: Vec<String>, map: &Vec<Record>,  i: i32) -> (i32,Vec<String>) {
	if "COM"==orb {
		(i,found)
	} else {
		for mass in map {
			if mass.1 == orb {
				let mut x = found.clone();
				x.push(String::from(&mass.0));
				// println!("{:?}",x);
				if i==0 {
					return get_path(&mass.0, x,&map, 1);
				} else {
					return get_path(&mass.0, x, &map,i+1);
				}
			}
		}
		(-1,vec![])
	}
}

