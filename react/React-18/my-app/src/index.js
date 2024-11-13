import React from 'react'
import ReactDOM from 'react-dom/client'

import './index.css'

const Books = [
  {
    image:
      'https://images-na.ssl-images-amazon.com/images/I/71xXzFQz7DL._AC_UL900_SR900,600_.jpg',
    title: "You're My Little Christmas Cookie",
    author: 'Nicola Edwards',
    id: 1,
  },
  {
    image:
      'https://images-na.ssl-images-amazon.com/images/I/81P9B8sY4AL._AC_UL900_SR900,600_.jpg',
    title: 'How To Catch A Turkey',
    author: 'Adam Wallace',
    id: 2,
  },
]

const BookList = () => {
  return (
    <section className="booklist">
      <EventExamples />

      {Books.map((book) => {
        return <Book {...book} key={book.id} />
      })}
    </section>
  )
}

const EventExamples = () => {
  const handleFormInput = (e) => {
    console.log(e.target)
    console.log(e.target.name)
    console.log(e.target.value)
    console.log('handle form input')
  }
  // const handleButtonClick = () => {
  //   alert('handle button click')
  // }
  const handleFormSubmission = (e) => {
    e.preventDefault()
    console.log('form submitted')
  }
  return (
    <section>
      <form onSubmit={handleFormSubmission}>
        <h2>Typical Form</h2>
        <input
          type="text"
          name="example"
          onChange={handleFormInput}
          style={{ margin: '1rem 0' }}
        />
      </form>
      <button onClick={(e) => console.log('herro thele')
      }>click me</button>
    </section>
  )
}

const Book = (props) => {
  const { image, title, author } = props

  return (
    <article className="book">
      <img src={image} alt={title} />
      <h2>{title}</h2>
      <h4>{author}</h4>
    </article>
  )
}

const root = ReactDOM.createRoot(document.getElementById('root'))

root.render(<BookList />)

// 12 - Booklist ~ Coding Addict
