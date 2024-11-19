import React from 'react'
import { people } from '../data'

const List = () => {
  return (
    <div>
      {people.map((person) => {
        return  <h2 key={person.id}>{person.name}</h2>
      })}
    </div>
  )
}

export default List
