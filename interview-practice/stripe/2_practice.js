
// 1 1 2 2 2 3 10 11 11 11 11

const evaluate_requests = (requests) => {
    let  wndow = []
    console.log(requests)
    for (let i = 0; i < requests.length; i++){
        // drop anything older than current timestamp - 4 seconds ago
        while (wndow.length > 0 && wndow[0] < requests[i] - 4) {
                wndow.shift()
        }
       if (wndow.length < 3){
            wndow.push(requests[i])
            console.log(true)
        } else {
            console.log(false)
        }
    }
        return wndow
    }

const input = "1 1 2 2 2 3 10 11 11 11 11";
const timestamps = evaluate_requests(input.split(" ")).map(x => parseInt(x))

console.log(timestamps);
