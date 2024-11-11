import React from 'react'
import ReactDOM from 'react-dom/client'

import './index.css'

const image =
  'https://images-na.ssl-images-amazon.com/images/I/71xXzFQz7DL._AC_UL900_SR900,600_.jpg'
const title = "You're My Little Christmas Cookie"
const author = 'Nicola Edwards'



const BookList = () => {
  return (
    <section className="booklist">
      <Book image = {image} title = {title} author = {author} />
      <Book image = {image} title = {title} author = {author} />
      <Book image = {image} title = {title} author = {author} />
    </section>
  )
}

const Book = (props) => {
  console.log(props);
  
  return (
    <article className="book">
      <img src={props.image} alt={props.title} />
      <h2>{props.title}</h2>
      <h4>{props.author}</h4>
    </article>
  )
}

const root = ReactDOM.createRoot(document.getElementById('root'))

root.render(<BookList />)

// 12 - Booklist ~ Coding Addict
