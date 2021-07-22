/* 
messages.js: Small service that returns SHA256 hash digest of string and vice versa  

Scaling Question:  
What would the bottleneck(s) be in your implementation as you acquire more users? How you might scale your
microservice?  

The bottlenecks will be slow response times and risk of downtime  
I would spec out the machine(s) (cpu, ram) and later setup a load balancer to spread the traffic  
At a large scale, apply caching with sharding the data and memoizing results  
Also introduce a database replication system to offload storage closer to audiences  

Deployment Question: 
How would you improve your deployment process if you needed to maintain this application long term?  

I would introduce a CI/CD system with automated test coverage  
Deploy automation and version control will help with fast updates and rollbacks  
*/
var crypto = require('crypto');
const express = require('express');
const app = express();

app.use(express.json());
const messages = [
	{ 
		digest: '2c26b46b68ffc68ff99b453c1d30413413422d706483bfa0f98a5e886266e7ae', message: 'foo'
	}
];

app.get('/', (req,res) => {
	res.send('Hello world');
});

/* 
/messages/<hash> is a GET request that returns the original message. 
A request to a non-existent <hash> should return a 404 error. 
*/
app.get('/messages/:digest',  (req, res) => {
	const message =  messages.find(m => m.digest == (req.params.digest));
	if (!message) res.status(404).send({'err_msg': 'Message not found'});
	res.send({'message': message['message']});
});

/* 
/messages takes a message (a string) as a POST and returns the SHA256 
hash digest of that message (in hexadecimal format)
*/
app.post('/messages', (req,res) => {
	const message = {
		digest: crypto.createHash('sha256').update(req.body.message).digest('hex'),
		message: req.body.message
	}
	messages.push(message);
	res.send({'digest': message['digest']});
});

const port = process.env.PORT || 8080;
app.listen(port, () => console.log(`Listening on port ${port}...`));
